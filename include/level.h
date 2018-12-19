#ifndef LEVEL_H
#define LEVEL_H

#include "gamestate.h"
#include "texture.h"
#include "font.h"
#include "table.h"
#include "collisionobserver.h"
#include "audioobserver.h"
#include "ball.h"
#include "cue.h"

#include <vector>
#include <utility>

class Level : public GameState {
    Texture background;
    Texture p1, p2;
    Font f1;
    Texture b8, b1, b9;

    CollisionObserver collobserver;
    AudioObserver audio;
    Table tab;
    Ball balls[15] {};
    Ball cueball {};
    Cue cue {};
    SDL_Point pocket_sensors[6] {}; // Check if ball in the pocket

    std::vector<int> pockets {};
    bool moving_state = false;
    bool player1turn = true;
    bool move_was_made = false;
    int team_color = 0; // 0 = undefined, 1 = player1 kills solid, 2 = player1 kills stripes

public:
    Level();
    virtual ~Level() noexcept override = default;
    Level(const Level&) = delete;
    Level& operator=(const Level&) = delete;

    virtual void handle_events() override;
    virtual void logic() override;
    virtual void render() override;

private:
    void handle_when_still(SDL_Event& e);
    void create_balls();
    void create_cue_ball();
    void create_sensors();
    bool check_pocket(Ball& b);
    bool ball_off_table(Ball& b);
    std::pair<double,double> get_safe_pos();
    void render_head();
    void recenter_cue();
    void change_state();
};

#endif // LEVEL_H