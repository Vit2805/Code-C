#include <stdio.h>
#include <stdlib.h>
#include "errorState.h"
#include "musicPlayer.h"
#include "bufferingState.h"
#include "stoppedState.h"

// Forward declaration
static void pressPlay(PlayerState *state);
static void pressPause(PlayerState *state);
static void pressStop(PlayerState *state);
static void setContext(PlayerState *state, struct MusicPlayer *player);

PlayerState* errorStateCreate() {
    PlayerState *state = (PlayerState*)malloc(sizeof(PlayerState));
    state->pressPlay = pressPlay;
    state->pressPause = pressPause;
    state->pressStop = pressStop;
    state->setContext = setContext;
    state->player = NULL;
    
    return state;
}

static void pressPlay(PlayerState *state) {
    printf("Retrying... Going to Buffering state.\n");
    state->player->changeState(state->player, bufferingStateCreate());
}

static void pressPause(PlayerState *state) {
    printf("Error: Cannot pause. Still in Error state.\n");
}

static void pressStop(PlayerState *state) {
    printf("Stopping player. Going to Stopped state.\n");
    state->player->changeState(state->player, stoppedStateCreate());
}

static void setContext(PlayerState *state, struct MusicPlayer *player) {
    state->player = player;
}
