/*
 * File: sensor_fusion.c
 * Description: Program to create and manage a music playlist
 */

#include <stdio.h>

#define SAMPLES 3000
#define DT 0.02

typedef struct
{
    double time;
    double probability;
} SensorData;

typedef struct
{
    int id;
    double threshold;
    SensorData data[SAMPLES];
    int binary[SAMPLES];
} Sensor;

/* -------------------------------------------------- */
/* Generate measurement files                         */
/* -------------------------------------------------- */
void generate_measurement_files(void)
{
    FILE *f1 = fopen("sensor1.txt", "w");
    FILE *f2 = fopen("sensor2.txt", "w");

    int i;
    double t;

    for (i = 0; i < SAMPLES; i++)
    {
        t = i * DT;

        /* Sensor 1: 3 detections */
        double p1 = 0.2;
        if ((t >= 10 && t <= 20) ||
            (t >= 30 && t <= 40) ||
            (t >= 45 && t <= 55))
        {
            p1 = 0.9;
        }

        /* Sensor 2: 3 detections, one overlap */
        double p2 = 0.3;
        if ((t >= 15 && t <= 25) ||
            (t >= 30 && t <= 40) ||
            (t >= 50 && t <= 60))
        {
            p2 = 0.85;
        }

        fprintf(f1, "%.2f %.3f\n", t, p1);
        fprintf(f2, "%.2f %.3f\n", t, p2);
    }

    fclose(f1);
    fclose(f2);
}

/* -------------------------------------------------- */
/* Read sensor data                                   */
/* -------------------------------------------------- */
void read_sensor(const char *filename, Sensor *sensor)
{
    FILE *f = fopen(filename, "r");
    int i = 0;

    while (i < SAMPLES &&
           fscanf(f, "%lf %lf",
                  &sensor->data[i].time,
                  &sensor->data[i].probability) == 2)
    {
        i++;
    }

    fclose(f);
}

/* -------------------------------------------------- */
/* Print detection intervals                          */
/* -------------------------------------------------- */
void print_intervals(const char *label,
                     int signal[],
                     SensorData data[])
{
    int i;
    int active = 0;
    double start = 0.0;

    printf("%s detections:\n", label);

    for (i = 0; i < SAMPLES; i++)
    {
        if (!active && signal[i])
        {
            active = 1;
            start = data[i].time;
        }

        if (active && (!signal[i] || i == SAMPLES - 1))
        {
            double end = data[i - 1].time;
            printf("  Start: %.2f s  End: %.2f s\n", start, end);
            active = 0;
        }
    }
}

/* -------------------------------------------------- */
/* Main                                               */
/* -------------------------------------------------- */
int main(void)
{
    Sensor sensor1 = {1, 0.8};
    Sensor sensor2 = {2, 0.7};
    int fusion[SAMPLES];

    int i;

    generate_measurement_files();

    read_sensor("sensor1.txt", &sensor1);
    read_sensor("sensor2.txt", &sensor2);

    /* Thresholding and fusion */
    for (i = 0; i < SAMPLES; i++)
    {
        sensor1.binary[i] =
            (sensor1.data[i].probability > sensor1.threshold);

        sensor2.binary[i] =
            (sensor2.data[i].probability > sensor2.threshold);

        fusion[i] = sensor1.binary[i] && sensor2.binary[i];
    }

    /* Output results */
    printf("\n--- Object Detection Results ---\n\n");

    print_intervals("Sensor 1", sensor1.binary, sensor1.data);
    printf("\n");

    print_intervals("Sensor 2", sensor2.binary, sensor2.data);
    printf("\n");

    print_intervals("Fused signal (both sensors)", fusion, sensor1.data);

    return 0;
}
