#include <SFML/Graphics.hpp>
#include <chrono>
#include <cmath>
#include <time.h>
#include <random>
using namespace std::chrono;


const int WX = 1800;
const int WY = 900;
const int N = 2000;

int random(int min, int max) {
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    static std::default_random_engine e(seed);
    std::uniform_int_distribution<int> d(min, max);
    return d(e);
}

int main() {

    int i = 10, a = 100, c = 100, stop = 10, kol_prep = random(3, 7), size[7] = {0}, spx[10] = {0}, spy[10] = {0};
    int l = -1, w = 4, e = 0, d = 0, b[10] = {0}, str_1[7] = {0}, str_2[7] = {0};
    float q[10], rad = 57.2958, skt = 0.4, rotation = 0.3;

    size[3] = 700;
    size[4] = 600;
    size[5] = 500;
    size[6] = 400;
    size[7] = 400;

    sf::RenderWindow window(sf::VideoMode(WX, WY), "Tanks");
    sf::CircleShape *r = new sf::CircleShape[N];
    sf::CircleShape *borders = new sf::CircleShape[N];
    sf::RectangleShape *rect = new sf::RectangleShape[N];
    for (int j = 0; j < 10; j++){
        rect[j].setFillColor(sf::Color(128, 128, 128));
        rect[j].setOutlineColor(sf::Color(70, 70, 70));
        rect[j].setOutlineThickness(5);
        rect[j].setPosition(-1000, -1000);
    }

    for (int p = 0; p < 10; p++){
        r[p].setPosition(-100, -100);
    }

    for (int j = 0; j < 8; j++){
        borders[j].setRadius(10);
        borders[j].setFillColor(sf::Color::Black);
        borders[j].setOrigin(10, 10);
    }

    borders[0].setPosition(85, 80);
    borders[1].setPosition(115, 80);
    borders[2].setPosition(85, 120);
    borders[3].setPosition(115, 120);
    borders[4].setPosition(1700, 800);
    borders[5].setPosition(1700, 800);
    borders[6].setPosition(1700, 800);
    borders[7].setPosition(1700, 800);


    sf::RectangleShape big1(sf::Vector2f(3000, 3000));
    big1.setFillColor(sf::Color::Magenta);
    big1.setPosition(5000, 5000);

    sf::RectangleShape big2(sf::Vector2f(3000, 3000));
    big2.setFillColor(sf::Color::Cyan);
    big2.setPosition(5000, 5000);


    sf::CircleShape circle8(10.f);
    circle8.setFillColor(sf::Color::Black);
    circle8.setOrigin(10, 10);
    circle8.setPosition(-100, -100);

    sf::RectangleShape rectangle_1(sf::Vector2f(18.f, 20.f));
    rectangle_1.setOutlineThickness(2);
    rectangle_1.setOutlineColor(sf::Color::Black);
    rectangle_1.setPosition(100, 100);
    rectangle_1.setFillColor(sf::Color::Magenta);
    rectangle_1.setOrigin(9, 40);

    sf::RectangleShape rectangle(sf::Vector2f(50.f, 60.f));
    rectangle.setOutlineThickness(2);
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setPosition(100, 100);
    rectangle.setFillColor(sf::Color::Magenta);
    rectangle.setOrigin(25, 30);

    sf::RectangleShape rr1(sf::Vector2f(18.f, 20.f));
    rr1.setOutlineThickness(2);
    rr1.setOutlineColor(sf::Color::Black);
    rr1.setPosition(1700, 800);
    rr1.setFillColor(sf::Color::Cyan);
    rr1.setOrigin(9, 40);

    sf::RectangleShape rr(sf::Vector2f(50.f, 60.f));
    rr.setOutlineThickness(2);
    rr.setOutlineColor(sf::Color::Black);
    rr.setPosition(1700, 800);
    rr.setFillColor(sf::Color::Cyan);
    rr.setOrigin(25, 30);

    for (int j = 0; j < kol_prep; j++){
        str_1[j] = random(10, size[kol_prep]);
        str_2[j] = random(10, size[kol_prep]);
        rect[j].setSize(sf::Vector2f(str_1[j], str_2[j]));
        rect[j].setOrigin(str_1[j] / 2, str_2[j] / 2);
        rect[j].setPosition(random(200, 1600), random(300, 700));
    }


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        borders[0].setPosition(rectangle.getPosition().x - (rectangle.getOrigin().x - 10) * cos(rectangle.getRotation() / rad) + (22.5 * sin(rectangle.getRotation() / rad)),
                               rectangle.getPosition().y - (rectangle.getOrigin().y - 10) * sin(rectangle.getRotation() / rad) - (22.5 * cos(rectangle.getRotation() / rad)));
        borders[1].setPosition(rectangle.getPosition().x + (rectangle.getOrigin().x - 10) * cos(rectangle.getRotation() / rad) + (22.5 * sin(rectangle.getRotation() / rad)),
                               rectangle.getPosition().y + (rectangle.getOrigin().y - 10) * sin(rectangle.getRotation() / rad) - (22.5 * cos(rectangle.getRotation() / rad)));
        borders[2].setPosition(rectangle.getPosition().x - (rectangle.getOrigin().x - 10) * cos(rectangle.getRotation() / rad) - (22.5 * sin(rectangle.getRotation() / rad)),
                               rectangle.getPosition().y - (rectangle.getOrigin().y - 10) * sin(rectangle.getRotation() / rad) + (22.5 * cos(rectangle.getRotation() / rad)));
        borders[3].setPosition(rectangle.getPosition().x + (rectangle.getOrigin().x - 10) * cos(rectangle.getRotation() / rad) - (22.5 * sin(rectangle.getRotation() / rad)),
                               rectangle.getPosition().y + (rectangle.getOrigin().y - 10) * sin(rectangle.getRotation() / rad) + (22.5 * cos(rectangle.getRotation() / rad)));

        borders[4].setPosition(rr.getPosition().x - (rr.getOrigin().x - 10) * cos(rr.getRotation() / rad) + (22.5 * sin(rr.getRotation() / rad)),
                               rr.getPosition().y - (rr.getOrigin().y - 10) * sin(rr.getRotation() / rad) - (22.5 * cos(rr.getRotation() / rad)));
        borders[5].setPosition(rr.getPosition().x + (rr.getOrigin().x - 10) * cos(rr.getRotation() / rad) + (22.5 * sin(rr.getRotation() / rad)),
                               rr.getPosition().y + (rr.getOrigin().y - 10) * sin(rr.getRotation() / rad) - (22.5 * cos(rr.getRotation() / rad)));
        borders[6].setPosition(rr.getPosition().x - (rr.getOrigin().x - 10) * cos(rr.getRotation() / rad) - (22.5 * sin(rr.getRotation() / rad)),
                               rr.getPosition().y - (rr.getOrigin().y - 10) * sin(rr.getRotation() / rad) + (22.5 * cos(rr.getRotation() / rad)));
        borders[7].setPosition(rr.getPosition().x + (rr.getOrigin().x - 10) * cos(rr.getRotation() / rad) - (22.5 * sin(rr.getRotation() / rad)),
                               rr.getPosition().y + (rr.getOrigin().y - 10) * sin(rr.getRotation() / rad) + (22.5 * cos(rr.getRotation() / rad)));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            rectangle.move(0 + skt * sin(rectangle_1.getRotation() / rad), skt * -cos(rectangle_1.getRotation() / rad));
            rectangle_1.move(0 + skt * sin(rectangle_1.getRotation() / rad), skt * -cos(rectangle_1.getRotation() / rad));
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                rectangle_1.rotate(rotation);
                rectangle.rotate(rotation);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                rectangle_1.rotate(-rotation);
                rectangle.rotate(-rotation);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            rectangle.move(0 + skt * -sin(rectangle_1.getRotation() / rad), skt * cos(rectangle_1.getRotation() / rad));
            rectangle_1.move(0 + skt * -sin(rectangle_1.getRotation() / rad), skt * cos(rectangle_1.getRotation() / rad));
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                rectangle_1.rotate(rotation);
                rectangle.rotate(rotation);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                rectangle_1.rotate(-rotation);
                rectangle.rotate(-rotation);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            rr.move(0 + skt * sin(rr.getRotation() / rad), skt * -cos(rr.getRotation() / rad));
            rr1.move(0 + skt * sin(rr1.getRotation() / rad), skt * -cos(rr1.getRotation() / rad));
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                rr1.rotate(rotation);
                rr.rotate(rotation);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                rr1.rotate(-rotation);
                rr.rotate(-rotation);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            rr.move(0 + skt * -sin(rr.getRotation() / rad), skt * cos(rr.getRotation() / rad));
            rr1.move(0 + skt * -sin(rr1.getRotation() / rad), skt * cos(rr1.getRotation() / rad));
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                rr1.rotate(rotation);
                rr.rotate(rotation);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                rr1.rotate(-rotation);
                rr.rotate(-rotation);
            }
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)){
            if (spx[0] == 0 || spx[1] == 0 || spx[2] == 0 || spx[3] == 0 || spx[4] == 0) {
                a -= 1;
            }
        }
        else {
            a = 10;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Insert)){
            if (spx[5] == 0 || spx[6] == 0 || spx[7] == 0 || spx[8] == 0 || spx[9] == 0) {
                c -= 1;
            }
        }
        else {
            c = 10;
        }

        for (int j = 0; j < 10; j++){
            if (spx[j] == 0 && r[j].getPosition().x > 0 && r[j].getPosition().x < WX && r[j].getPosition().y > 0 && r[j].getPosition().y < WY && (big1.getPosition().x != 0 && big2.getPosition().x != 0)){
                spx[j] = 1;
                spy[j] = 1;
            }
        }

        if (a == 0){
            l += 1;
            if (l == 5)
                l = 0;
            i = 0;
            if (spx[0] == 0)
                l = 0;
            if (spx[1] == 0)
                l = 1;
            if (spx[2] == 0)
                l = 2;
            if (spx[3] == 0)
                l = 3;
            if (spx[4] == 0)
                l = 4;
            r[l].setFillColor(sf::Color::Magenta);
            r[l].setOutlineColor(sf::Color::Black);
            r[l].setOutlineThickness(2);
            r[l].setRadius(10.f);
            r[l].setOrigin(10, 10);
            r[l].setPosition(rectangle.getPosition().x + ((rectangle.getOrigin().y * 5 / 6) * sin(rectangle.getRotation() / rad)), rectangle.getPosition().y - ((rectangle.getOrigin().y * 5 / 6) * cos(rectangle.getRotation() / rad)));
            q[l] = rectangle_1.getRotation();
            a = 100;
        }

        if (c == 0){
            w += 1;
            if (w == 10)
                w = 5;
            i = 0;
            if (spx[5] == 0)
                w = 5;
            if (spx[6] == 0)
                w = 6;
            if (spx[7] == 0)
                w = 7;
            if (spx[8] == 0)
                w = 8;
            if (spx[9] == 0)
                w = 9;
            r[w].setFillColor(sf::Color::Cyan);
            r[w].setOutlineColor(sf::Color::Black);
            r[w].setOutlineThickness(2);
            r[w].setRadius(10.f);
            r[w].setOrigin(10, 10);
            r[w].setPosition(rr.getPosition().x + ((rr.getOrigin().y * 5 / 6) * sin(rr.getRotation() / rad)), rr.getPosition().y - ((rr.getOrigin().y * 5 / 6) * cos(rr.getRotation() / rad)));
            q[w] = rr.getRotation();
            c = 100;
        }

        for (int k = 0; k < 10; k++){
            if (i < 1){
                r[k].move(spx[k] * sin(q[k] / rad), spy[k] * -cos(q[k] / rad));
            }
        }

        for (int j = 0; j < 10; j++){
            if (r[j].getPosition().x + r[j].getRadius() > WX && r[j].getPosition().x + r[j].getRadius() < (WX + 200) || r[j].getPosition().x - r[j].getRadius() < 0 && r[j].getPosition().x - r[j].getRadius() > -200){
                spx[j] = -spx[j];
                b[j] = b[j] + 1;
            }
            if (r[j].getPosition().y + r[j].getRadius() > WY && r[j].getPosition().y + r[j].getRadius() < (WY + 200) || r[j].getPosition().y - r[j].getRadius() < 0 && r[j].getPosition().y - r[j].getRadius() > -200) {
                spy[j] = -spy[j];
                b[j] = b[j] + 1;
            }
            if (b[j] > 10) {
                r[j].setPosition(-1000, -1000);
                spy[j] = 0;
                spx[j] = 0;
                b[j] = 0;
            }
        }

        if (rectangle.getPosition().x + 25 > WX) {
            rectangle.setPosition(WX - 25, rectangle.getPosition().y);
            rectangle_1.setPosition(WX - 25, rectangle_1.getPosition().y);
        }
        if (rectangle.getPosition().x - 25 < 0) {
            rectangle.setPosition(25, rectangle.getPosition().y);
            rectangle_1.setPosition(25, rectangle_1.getPosition().y);
        }
        if (rectangle.getPosition().y + 25 > WY) {
            rectangle.setPosition(rectangle.getPosition().x, WY - 25);
            rectangle_1.setPosition(rectangle_1.getPosition().x, WY - 25);
        }
        if (rectangle.getPosition().y - 25 < 0) {
            rectangle.setPosition(rectangle.getPosition().x, 25);
            rectangle_1.setPosition(rectangle_1.getPosition().x, 25);
        }



        if (rr.getPosition().x + 25 > WX) {
            rr.setPosition(WX - 25, rr.getPosition().y);
            rr1.setPosition(WX - 25, rr1.getPosition().y);
        }
        if (rr.getPosition().x - 25 < 0) {
            rr.setPosition(25, rr.getPosition().y);
            rr1.setPosition(25, rr1.getPosition().y);
        }
        if (rr.getPosition().y + 25 > WY) {
            rr.setPosition(rr.getPosition().x, WY - 25);
            rr1.setPosition(rr1.getPosition().x, WY - 25);
        }
        if (rr.getPosition().y - 25 < 0) {
            rr.setPosition(rr.getPosition().x, 25);
            rr1.setPosition(rr1.getPosition().x, 25);
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            rectangle_1.rotate(rotation);
            rectangle.rotate(rotation);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            rectangle_1.rotate(-rotation);
            rectangle.rotate(-rotation);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            rr.rotate(rotation);
            rr1.rotate(rotation);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            rr1.rotate(-rotation);
            rr.rotate(-rotation);
        }

        for (int j = 0; j < 7; j++){
            if (rectangle.getPosition().x > rect[j].getPosition().x && rectangle.getPosition().y > rect[j].getPosition().y - rect[j].getOrigin().y &&
                                                                               rectangle.getPosition().y < rect[j].getPosition().y + rect[j].getOrigin().y){
                if (rectangle.getPosition().x - 25 < rect[j].getPosition().x + rect[j].getOrigin().x){
                    rectangle.setPosition(rect[j].getPosition().x + rect[j].getOrigin().x + 25, rectangle.getPosition().y);
                    rectangle_1.setPosition(rect[j].getPosition().x + rect[j].getOrigin().x + 25, rectangle_1.getPosition().y);
                }
            }
            if (rectangle.getPosition().x < rect[j].getPosition().x && rectangle.getPosition().y > rect[j].getPosition().y - rect[j].getOrigin().y &&
                                                                       rectangle.getPosition().y < rect[j].getPosition().y + rect[j].getOrigin().y){
                if (rectangle.getPosition().x + 25 > rect[j].getPosition().x - rect[j].getOrigin().x){
                    rectangle.setPosition(rect[j].getPosition().x - rect[j].getOrigin().x - 25, rectangle.getPosition().y);
                    rectangle_1.setPosition(rect[j].getPosition().x - rect[j].getOrigin().x - 25, rectangle_1.getPosition().y);
                }
            }
            if (rectangle.getPosition().y > rect[j].getPosition().y && rectangle.getPosition().x > rect[j].getPosition().x - rect[j].getOrigin().x &&
                                                                       rectangle.getPosition().x < rect[j].getPosition().x + rect[j].getOrigin().x){
                if (rectangle.getPosition().y - 25 < rect[j].getPosition().y + rect[j].getOrigin().y){
                    rectangle.setPosition(rectangle.getPosition().x, rect[j].getPosition().y + rect[j].getOrigin().y + 25);
                    rectangle_1.setPosition(rectangle_1.getPosition().x, rect[j].getPosition().y + rect[j].getOrigin().y + 25);
                }
            }
            if (rectangle.getPosition().y < rect[j].getPosition().y && rectangle.getPosition().x > rect[j].getPosition().x - rect[j].getOrigin().x &&
                                                                       rectangle.getPosition().x < rect[j].getPosition().x + rect[j].getOrigin().x){
                if (rectangle.getPosition().y + 25 > rect[j].getPosition().y - rect[j].getOrigin().y){
                    rectangle.setPosition(rectangle.getPosition().x, rect[j].getPosition().y - rect[j].getOrigin().y - 25);
                    rectangle_1.setPosition(rectangle_1.getPosition().x, rect[j].getPosition().y - rect[j].getOrigin().y - 25);
                }
            }

            if (rr.getPosition().x > rect[j].getPosition().x && rr.getPosition().y > rect[j].getPosition().y - rect[j].getOrigin().y &&
                rr.getPosition().y < rect[j].getPosition().y + rect[j].getOrigin().y){
                if (rr.getPosition().x - 25 < rect[j].getPosition().x + rect[j].getOrigin().x){
                    rr.setPosition(rect[j].getPosition().x + rect[j].getOrigin().x + 25, rr.getPosition().y);
                    rr1.setPosition(rect[j].getPosition().x + rect[j].getOrigin().x + 25, rr1.getPosition().y);
                }
            }
            if (rr.getPosition().x < rect[j].getPosition().x && rr.getPosition().y > rect[j].getPosition().y - rect[j].getOrigin().y &&
                rr.getPosition().y < rect[j].getPosition().y + rect[j].getOrigin().y){
                if (rr.getPosition().x + 25 > rect[j].getPosition().x - rect[j].getOrigin().x){
                    rr.setPosition(rect[j].getPosition().x - rect[j].getOrigin().x - 25, rr.getPosition().y);
                    rr1.setPosition(rect[j].getPosition().x - rect[j].getOrigin().x - 25, rr1.getPosition().y);
                }
            }
            if (rr.getPosition().y > rect[j].getPosition().y && rr.getPosition().x > rect[j].getPosition().x - rect[j].getOrigin().x &&
                rr.getPosition().x < rect[j].getPosition().x + rect[j].getOrigin().x){
                if (rr.getPosition().y - 25 < rect[j].getPosition().y + rect[j].getOrigin().y){
                    rr.setPosition(rr.getPosition().x, rect[j].getPosition().y + rect[j].getOrigin().y + 25);
                    rr1.setPosition(rr1.getPosition().x, rect[j].getPosition().y + rect[j].getOrigin().y + 25);
                }
            }
            if (rr.getPosition().y < rect[j].getPosition().y && rr.getPosition().x > rect[j].getPosition().x - rect[j].getOrigin().x &&
                rr.getPosition().x < rect[j].getPosition().x + rect[j].getOrigin().x){
                if (rr.getPosition().y + 25 > rect[j].getPosition().y - rect[j].getOrigin().y){
                    rr.setPosition(rr.getPosition().x, rect[j].getPosition().y - rect[j].getOrigin().y - 25);
                    rr1.setPosition(rr1.getPosition().x, rect[j].getPosition().y - rect[j].getOrigin().y - 25);
                }
            }
            for (int p = 0; p < 10; p++){
                if (rect[j].getPosition().x > r[p].getPosition().x && r[p].getPosition().y > rect[j].getPosition().y - rect[j].getOrigin().y &&
                        r[p].getPosition().y < rect[j].getPosition().y + rect[j].getOrigin().y){
                    if (r[p].getPosition().x + r[p].getRadius() > rect[j].getPosition().x - rect[j].getOrigin().x) {
                        spx[p] = -spx[p];
                        b[p] += 1;
                    }
                }
                if (rect[j].getPosition().x < r[p].getPosition().x && r[p].getPosition().y > rect[j].getPosition().y - rect[j].getOrigin().y &&
                    r[p].getPosition().y < rect[j].getPosition().y + rect[j].getOrigin().y){
                    if (r[p].getPosition().x - r[p].getRadius() < rect[j].getPosition().x + rect[j].getOrigin().x) {
                        spx[p] = -spx[p];
                        b[p] += 1;
                    }
                }
                if (rect[j].getPosition().y > r[p].getPosition().y && r[p].getPosition().x > rect[j].getPosition().x - rect[j].getOrigin().x &&
                    r[p].getPosition().x < rect[j].getPosition().x + rect[j].getOrigin().x){
                    if (r[p].getPosition().y + r[p].getRadius() > rect[j].getPosition().y - rect[j].getOrigin().y) {
                        spy[p] = -spy[p];
                        b[p] += 1;
                    }
                }
                if (rect[j].getPosition().y < r[p].getPosition().y && r[p].getPosition().x > rect[j].getPosition().x - rect[j].getOrigin().x &&
                    r[p].getPosition().x < rect[j].getPosition().x + rect[j].getOrigin().x){
                    if (r[p].getPosition().y - r[p].getRadius() < rect[j].getPosition().y + rect[j].getOrigin().y) {
                        spy[p] = -spy[p];
                        b[p] += 1;
                    }
                }
            }
        }

        for (int j = 0; j < 5; j++){
            for (int p = 4; p < 7; p++) {
                if (sqrt((rr.getPosition().x - r[j].getPosition().x) * (rr.getPosition().x - r[j].getPosition().x) +
                         (rr.getPosition().y - r[j].getPosition().y) * (rr.getPosition().y - r[j].getPosition().y)) <
                    25 + r[j].getRadius() || sqrt((borders[p].getPosition().x - r[j].getPosition().x) * (borders[p].getPosition().x - r[j].getPosition().x) +
                    (borders[p].getPosition().y - r[j].getPosition().y) * (borders[p].getPosition().y - r[j].getPosition().y)) < borders[p].getRadius() + r[j].getRadius()) {
                    for (int l = 0; l < 10; l++){
                        spx[l] = 0;
                        spy[l] = 0;
                    }
                    stop = 100;
                    circle8.setPosition(r[j].getPosition());
                    r[j].setPosition(0, 0);
                    big1.setPosition(0, 0);
                    skt = 0;
                    rotation = 0;
                }
            }
        }

        for (int j = 5; j < 10; j++){
            for (int p = 0; p < 4; p++) {
                if (sqrt((rectangle.getPosition().x - r[j].getPosition().x) *
                         (rectangle.getPosition().x - r[j].getPosition().x) +
                         (rectangle.getPosition().y - r[j].getPosition().y) *
                         (rectangle.getPosition().y - r[j].getPosition().y)) < 25 + r[j].getRadius() ||
                        sqrt((borders[p].getPosition().x - r[j].getPosition().x) * (borders[p].getPosition().x - r[j].getPosition().x) +
                             (borders[p].getPosition().y - r[j].getPosition().y) * (borders[p].getPosition().y - r[j].getPosition().y)) < borders[p].getRadius() + r[j].getRadius()) {
                    for (int l = 0; l < 10; l++){
                        spx[l] = 0;
                        spy[l] = 0;
                    }
                    stop = 100;
                    circle8.setPosition(r[j].getPosition());
                    r[j].setPosition(0, 0);
                    big2.setPosition(0, 0);
                    skt = 0;
                    rotation = 0;
                }
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            stop -= 1;
        }

        if (stop == 0){
            for (int j = 0; j < 10; j++){
                r[j].setPosition(-1000, -1000);
                rect[j].setPosition(-1000, -1000);
            }
            kol_prep = random(3, 7);
            for (int j = 0; j < kol_prep; j++){
//                int red = random(0, 255), green = random(0, 255), blue = random(0, 255);
                str_1[j] = random(10, size[kol_prep]);
                str_2[j] = random(10, size[kol_prep]);
                rect[j].setSize(sf::Vector2f(str_1[j], str_2[j]));
                rect[j].setOrigin(str_1[j] / 2, str_2[j] / 2);
//                rect[j].setFillColor(sf::Color(red, green, blue));
//                rect[j].setOutlineColor(sf::Color(red - 10, green - 10, blue - 10));
                rect[j].setPosition(random(200, 1600), random(300, 700));
            }
            big1.setPosition(5000, 5000);
            big2.setPosition(5000, 5000);
            rectangle_1.setPosition(100, 100);
            rectangle.setPosition(100, 100);
            rr1.setPosition(1700, 800);
            rr.setPosition(1700, 800);
            rectangle_1.setRotation(0);
            rectangle.setRotation(0);
            rr.setRotation(0);
            rr1.setRotation(0);
            skt = 0.4;
            rotation = 0.3;
            circle8.setPosition(-1000, -1000);
            stop = 100;
        }



        window.clear(sf::Color(230, 230,250));
        window.draw(big1);
        window.draw(big2);
        window.draw(rectangle);
        window.draw(rectangle_1);
        window.draw(rr);
        window.draw(rr1);
        window.draw(circle8);
        for (int j = 0; j < 10; j++) {
            window.draw(rect[j]);
            window.draw(r[j]);
        }
//        window.draw(borders[0]);
//        window.draw(borders[1]);
//        window.draw(borders[2]);
//        window.draw(borders[3]);
//        window.draw(borders[4]);
//        window.draw(borders[5]);
//        window.draw(borders[6]);
//        window.draw(borders[7]);
        window.display();
    }
    return 0;
}
