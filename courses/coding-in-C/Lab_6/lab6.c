#include <stdio.h>
#include <stdlib.h>

#define SAMPLES 3000
#define STEP_SIZE 0.02
#define THRESHOLD_SEN1 0.8
#define THRESHOLD_SEN2 0.7
#define NUM_SENSORS 2

typedef enum {
    NOT_DETECTED = 0,
    DETECTED = 1
} State;

typedef struct 
{
    double time, probability;
} SensorData;

typedef struct 
{
    int id;
    int binary[SAMPLES];
    double threshold;
    int interval_index;
    double intervals[SAMPLES][2];
    SensorData data[SAMPLES];
} Sensor;


void readSensorData(FILE* fp, Sensor *sensor) {
    double time;
    double probability;
    int line_count = 0;

    while (fscanf(fp, "%lf %lf", &time, &probability) == 2) {
        sensor->data[line_count].time = time;
        sensor->data[line_count].probability = probability;

        if(probability > sensor->threshold) {
            sensor->binary[line_count] = 1;
        } else {sensor->binary[line_count] = 0;}

        line_count++;
    }

    fclose(fp);
}


void extractInterval(Sensor *sensor) {
    State cur_state = NOT_DETECTED;
    double start_time = 0.0;

    for (int i = 0; i < SAMPLES; i++) {

        if (!cur_state && sensor->binary[i] == 1) {
            sensor->intervals[sensor->interval_index][0] = sensor->data[i].time;
            start_time = sensor->data[i].time;
            sensor->interval_index++;
            cur_state = DETECTED;
        }

        if (cur_state && sensor->binary[i] == 0) {
            sensor->intervals[sensor->interval_index-1][1] = sensor->data[i-1].time;
            cur_state = NOT_DETECTED;
            printf("Start: %.2fs \t", start_time);
            printf("Ende: %.2fs \n", sensor->data[i-1].time);
        }
    }

    if (cur_state) {
        double end_time = sensor->data[SAMPLES-1].time + STEP_SIZE;
        sensor->intervals[sensor->interval_index-1][1] = end_time;
        printf("Start: %.2fs \t", start_time);
        printf("Ende: %.2fs \n", end_time);
    }
}


void overlappingInterval(Sensor *sensor0, Sensor *sensor1){
    for (int i = 0; i < sensor0->interval_index; i++)
    {
        for (int j = 0; j < sensor1->interval_index; j++)
        {
            if (sensor0->intervals[i][0] == sensor1->intervals[j][0])
            {
                if (sensor0->intervals[i][1] == sensor1->intervals[j][1])
                {
                    printf("Start: %.2fs\t", sensor0->intervals[i][0]);
                    printf("Ende: %.2fs\n\n", sensor0->intervals[i][1]);
                }
            }
        }
    }
}


int main() {
    Sensor sensor[NUM_SENSORS];
    sensor[0].threshold = THRESHOLD_SEN1;
    sensor[1].threshold = THRESHOLD_SEN2;

    FILE *sensor_data1, *sensor_data2 = NULL;
    sensor_data1 = fopen("sensor1.txt", "r");
    sensor_data2 = fopen("sensor2.txt", "r");

    if (sensor_data1 == NULL || sensor_data2 == NULL) {
        printf("Fehler!\n"); exit(1);
    } else {
        readSensorData(sensor_data1, &sensor[0]);
        readSensorData(sensor_data2, &sensor[1]);
    }

    for (int i = 0; i < NUM_SENSORS; i++) {
        printf("\nSensor %d detections:\n", i+1);
        sensor[i].interval_index = 0;
        extractInterval(&sensor[i]);
    }

    printf("\nFused signal (both sensors): \n");
    
    for (int i = 0; i < NUM_SENSORS; i++) {
        for (int j = i+1; j < NUM_SENSORS; j++) {
            overlappingInterval(&sensor[i], &sensor[j]);
        }
    }
}