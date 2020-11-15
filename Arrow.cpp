//
// Created by hang-tran on 11/12/20.
//
#include <cmath>
#include "Arrow.h"
Arrow::Arrow(string name) {
    currentAnimation = Animation(name, 1.f/60);
    currentAnimation.setTexture(s);
    s.setPosition(300.0f, 533.0f);
    s.setOrigin(s.getTexture()->getSize().x * 0.5f, -121.0f);
    this->body.setSize((Vector2f)s.getTexture()->getSize());
    this->body.setOrigin(s.getTexture()->getSize().x * 0.5f, -121.0f);
    this->body.setPosition(300.0f, 533.0f);
    this->check = true;
    //this->gameover = true;
    this->angle = 0.f;
}
void Arrow::Draw(RenderWindow &rd) {
    //Entity::Draw(rd);
    rd.draw(s);
}
void Arrow::Update() {
    if(Keyboard::isKeyPressed(Keyboard::Space)){
        this->Velocity.y = -1.0f;
        this->Velocity.x = 0;
    }
    Move(this->Velocity);
}
void Arrow::Update2() {
    this->currentAnimation.setTexture(s);
}
void Arrow::Move(Vector2f velocity) {
    s.move(velocity);
    body.setPosition(s.getPosition());
}
bool Arrow::isCollision(Entity* other) {
    if(other->getBody().getGlobalBounds().intersects(s.getGlobalBounds())){
        check = false;
        gameover = true;
        return true;
    }
    return false;
}
void Arrow::Rota() {
    angle = 0.1f;
    body.rotate(angle);
    s.rotate(angle);
}
bool Arrow::isCollision(Entity other) {
    if(other.getBody().getGlobalBounds().intersects(s.getGlobalBounds())){
        gameover = false;
        return true;
    }
    return false;
}
void Arrow::set_stage(int tmp) {
    this->stage = tmp;
}
int Arrow::get_stage() {
    return stage;
}
bool Arrow::check_ck() {
    return check;
}
bool Arrow::getgameover() {
    return this->gameover;
}