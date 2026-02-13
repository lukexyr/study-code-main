#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_PLAYLISTS 1

typedef struct Song
{
    char *title, *artist;
    struct Song *next;
} Song;

typedef struct
{
    Song *first;
} Playlist;

void init_playlist(Playlist *pl)
{
    pl->first = NULL;
}

char *read_line(void)
{
    char *buffer = NULL;
    size_t len = 0;

    getline(&buffer, &len, stdin);
    buffer[strcspn(buffer, "\n")] = 0;

    return buffer;
}

void add_song(Playlist *pl)
{
    Song *next_song = malloc(sizeof(Song));
    if (!next_song)
    {
        printf("Memory couldn't be allocated correctly\n");
        return;
    }

    printf("Title: ");
    next_song->title = read_line();
    printf("Artist: ");
    next_song->artist = read_line();

    if (!next_song->title || !next_song->artist)
    {
        printf("Memory couldn't be allocated correctly\n");
        free(next_song->title);
        free(next_song->artist);
        free(next_song);
        return;
    }

    next_song->next = NULL;
    if (pl->first == NULL)
    {
        pl->first = next_song;
        return;
    }

    Song *current = pl->first;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = next_song;
}

void delete_firstSong(Playlist *pl)
{
    if (pl->first == NULL) return;

    Song *temp = pl->first;
    pl->first = pl->first->next;

    free(temp->title);
    free(temp->artist);
    free(temp);
}

void delete_playlist(Playlist *pl)
{
    while (pl->first != NULL)
    {
        delete_firstSong(pl);
    }
}

void print_playlist(Playlist *pl)
{
    Song *current = pl->first;
    while (current != NULL)
    {
        printf("\nTitle: %s, Artist: %s\n", current->title, current->artist);
        current = current->next;
    }
}

int main()
{
    Playlist *pl[NUM_PLAYLISTS];

    for (int i = 0; i < NUM_PLAYLISTS; i++)
    {
        pl[i] = malloc(sizeof(Playlist));
        init_playlist(pl[i]);
    }

    add_song(pl[0]);
    add_song(pl[0]);
    delete_firstSong(pl[0]);

    if (pl[0]->first != NULL)
    {
        print_playlist(pl[0]);
    } else {
        printf("Empty Playlist"); }
    
    for (int i = 0; i < NUM_PLAYLISTS; i++)
    {
        delete_playlist(pl[i]);
        free(pl[i]);
    }
}