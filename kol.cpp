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
    size[0] = 0;
    size[1] = 0;
    size[2] = 0;
    size[3] = 500;
    size[4] = 400;
    size[5] = 300;
    size[6] = 200;
    size[7] = 100;

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

    borders[0].setRadius(10);
    borders[0].setFillColor(sf::Color::Black);
    borders[0].setOrigin(10, 10);
    borders[0].setPosition(85, 80);
    borders[0].setPosition(85, 80);
    borders[1].setRadius(10);
    borders[1].setFillColor(sf::Color::Black);
    borders[1].setOrigin(10, 10);
    borders[1].setPosition(115, 80);
    borders[2].setRadius(10);
    borders[2].setFillColor(sf::Color::Black);
    borders[2].setOrigin(10, 10);
    borders[2].setPosition(85, 120);
    borders[3].setRadius(10);
    borders[3].setFillColor(sf::Color::Black);
    borders[3].setOrigin(10, 10);
    borders[3].setPosition(115, 120);
    borders[4].setRadius(10);
    borders[4].setFillColor(sf::Color::Black);
    borders[4].setOrigin(10, 10);
    borders[4].setPosition(1700, 800);
    borders[5].setRadius(10);
    borders[5].setFillColor(sf::Color::Black);
    borders[5].setOrigin(10, 10);
    borders[5].setPosition(1700, 800);
    borders[6].setRadius(10);
    borders[6].setFillColor(sf::Color::Black);
    borders[6].setOrigin(10, 10);
    borders[6].setPosition(1700, 800);
    borders[7].setRadius(10);
    borders[7].setFillColor(sf::Color::Black);
    borders[7].setOrigin(10, 10);
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

        if (spx[0] == 0 && r[0].getPosition().x > 0 && r[0].getPosition().x < WX && r[0].getPosition().y > 0 && r[0].getPosition().y < WY && (big1.getPosition().x != 0 && big2.getPosition().x != 0)){
            spx[0] = 1;
            spy[0] = 1;
        }
        if (spx[1] == 0 && r[1].getPosition().x > 0 && r[1].getPosition().x < WX && r[1].getPosition().y > 0 && r[1].getPosition().y < WY && (big1.getPosition().x != 0 && big2.getPosition().x != 0)){
            spx[1] = 1;
            spy[1] = 1;
        }
        if (spx[2] == 0 && r[2].getPosition().x > 0 && r[2].getPosition().x < WX && r[2].getPosition().y > 0 && r[2].getPosition().y < WY && (big1.getPosition().x != 0 && big2.getPosition().x != 0)){
            spx[2] = 1;
            spy[2] = 1;
        }
        if (spx[3] == 0 && r[3].getPosition().x > 0 && r[3].getPosition().x < WX && r[3].getPosition().y > 0 && r[3].getPosition().y < WY && (big1.getPosition().x != 0 && big2.getPosition().x != 0)){
            spx[3] = 1;
            spy[3] = 1;
        }
        if (spx[4] == 0 && r[4].getPosition().x > 0 && r[4].getPosition().x < WX && r[4].getPosition().y > 0 && r[4].getPosition().y < WY && (big1.getPosition().x != 0 && big2.getPosition().x != 0)){
            spx[4] = 1;
            spy[4] = 1;
        }
        if (spx[5] == 0 && r[5].getPosition().x > 0 && r[5].getPosition().x < WX && r[5].getPosition().y > 0 && r[5].getPosition().y < WY && (big1.getPosition().x != 0 && big2.getPosition().x != 0)){
            spx[5] = 1;
            spy[5] = 1;
        }
        if (spx[6] == 0 && r[6].getPosition().x > 0 && r[6].getPosition().x < WX && r[6].getPosition().y > 0 && r[6].getPosition().y < WY && (big1.getPosition().x != 0 && big2.getPosition().x != 0)){
            spx[6] = 1;
            spy[6] = 1;
        }
        if (spx[7] == 0 && r[7].getPosition().x > 0 && r[7].getPosition().x < WX && r[7].getPosition().y > 0 && r[7].getPosition().y < WY && (big1.getPosition().x != 0 && big2.getPosition().x != 0)){
            spx[7] = 1;
            spy[7] = 1;
        }
        if (spx[8] == 0 && r[8].getPosition().x > 0 && r[8].getPosition().x < WX && r[8].getPosition().y > 0 && r[8].getPosition().y < WY && (big1.getPosition().x != 0 && big2.getPosition().x != 0)){
            spx[8] = 1;
            spy[8] = 1;
        }
        if (spx[9] == 0 && r[9].getPosition().x > 0 && r[9].getPosition().x < WX && r[9].getPosition().y > 0 && r[9].getPosition().y < WY && (big1.getPosition().x != 0 && big2.getPosition().x != 0)){
            spx[9] = 1;
            spy[9] = 1;
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

        if (r[0].getPosition().x + r[0].getRadius() > WX && r[0].getPosition().x + r[0].getRadius() < (WX + 200) || r[0].getPosition().x - r[0].getRadius() < 0 && r[0].getPosition().x - r[0].getRadius() > -200){
            spx[0] = -spx[0];
            b[0] = b[0] + 1;
        }
        if (r[0].getPosition().y + r[0].getRadius() > WY && r[0].getPosition().y + r[0].getRadius() < (WY + 200) || r[0].getPosition().y - r[0].getRadius() < 0 && r[0].getPosition().y - r[0].getRadius() > -200) {
            spy[0] = -spy[0];
            b[0] = b[0] + 1;
        }
        if (b[0] > 8) {
            r[0].setPosition(-1000, -1000);
            spy[0] = 0;
            spx[0] = 0;
            b[0] = 0;
        }
        if (r[1].getPosition().x + r[1].getRadius() > WX && r[1].getPosition().x + r[1].getRadius() < (WX + 200) || r[1].getPosition().x - r[1].getRadius() < 0 && r[1].getPosition().x - r[1].getRadius() > -200){
            spx[1] = -spx[1];
            b[1] = b[1] + 1;
        }
        if (r[1].getPosition().y + r[1].getRadius() > WY && r[1].getPosition().y + r[1].getRadius() < (WY + 200) || r[1].getPosition().y - r[1].getRadius() < 0 && r[1].getPosition().y - r[1].getRadius() > -200) {
            spy[1] = -spy[1];
            b[1] = b[1] + 1;
        }
        if (b[1] > 8) {
            r[1].setPosition(-1000, -1000);
            spy[1] = 0;
            spx[1] = 0;
            b[1] = 0;
        }
        if (r[2].getPosition().x + r[2].getRadius() > WX && r[2].getPosition().x + r[2].getRadius() < (WX + 200) || r[2].getPosition().x - r[2].getRadius() < 0 && r[2].getPosition().x - r[2].getRadius() > -200){
            spx[2] = -spx[2];
            b[2] = b[2] + 1;
        }
        if (r[2].getPosition().y + r[2].getRadius() > WY && r[2].getPosition().y + r[2].getRadius() < (WY + 200) || r[2].getPosition().y - r[2].getRadius() < 0 && r[2].getPosition().y - r[2].getRadius() > -200) {
            spy[2] = -spy[2];
            b[2] = b[2] + 1;
        }
        if (b[2] > 8) {
            r[2].setPosition(-1000, -1000);
            spy[2] = 0;
            spx[2] = 0;
            b[2] = 0;
        }
        if (r[3].getPosition().x + r[3].getRadius() > WX && r[3].getPosition().x + r[3].getRadius() < (WX + 200) || r[3].getPosition().x - r[3].getRadius() < 0 && r[3].getPosition().x - r[3].getRadius() > -200){
            spx[3] = -spx[3];
            b[3] = b[3] + 1;
        }
        if (r[3].getPosition().y + r[3].getRadius() > WY && r[3].getPosition().y + r[3].getRadius() < (WY + 200) || r[3].getPosition().y - r[3].getRadius() < 0 && r[3].getPosition().y - r[3].getRadius() > -200) {
            spy[3] = -spy[3];
            b[3] = b[3] + 1;
        }
        if (b[3] > 8) {
            r[3].setPosition(-1000, -1000);
            spy[3] = 0;
            spx[3] = 0;
            b[3] = 0;
        }
        if (r[4].getPosition().x + r[4].getRadius() > WX && r[4].getPosition().x + r[4].getRadius() < (WX + 200) || r[4].getPosition().x - r[4].getRadius() < 0 && r[4].getPosition().x - r[4].getRadius() > -200){
            spx[4] = -spx[4];
            b[4] = b[4] + 1;
        }
        if (r[4].getPosition().y + r[4].getRadius() > WY && r[4].getPosition().y + r[4].getRadius() < (WY + 200) || r[4].getPosition().y - r[4].getRadius() < 0 && r[4].getPosition().y - r[4].getRadius() > -200) {
            spy[4] = -spy[4];
            b[4] = b[4] + 1;
        }
        if (b[4] > 8) {
            r[4].setPosition(-1000, -1000);
            spy[4] = 0;
            spx[4] = 0;
            b[4] = 0;
        }
        if (r[5].getPosition().x + r[5].getRadius() > WX && r[5].getPosition().x + r[5].getRadius() < (WX + 200) || r[5].getPosition().x - r[5].getRadius() < 0 && r[5].getPosition().x - r[5].getRadius() > -200){
            spx[5] = -spx[5];
            b[5] = b[5] + 1;
        }
        if (r[5].getPosition().y + r[5].getRadius() > WY && r[5].getPosition().y + r[5].getRadius() < (WY + 200) || r[5].getPosition().y - r[5].getRadius() < 0 && r[5].getPosition().y - r[5].getRadius() > -200) {
            spy[5] = -spy[5];
            b[5] = b[5] + 1;
        }
        if (b[5] > 8) {
            r[5].setPosition(-1000, -1000);
            spy[5] = 0;
            spx[5] = 0;
            b[5] = 0;
        }
        if (r[6].getPosition().x + r[6].getRadius() > WX && r[6].getPosition().x + r[6].getRadius() < (WX + 200) || r[6].getPosition().x - r[6].getRadius() < 0 && r[6].getPosition().x - r[6].getRadius() > -200){
            spx[6] = -spx[6];
            b[6] = b[6] + 1;
        }
        if (r[6].getPosition().y + r[6].getRadius() > WY && r[6].getPosition().y + r[6].getRadius() < (WY + 200) || r[6].getPosition().y - r[6].getRadius() < 0 && r[6].getPosition().y - r[6].getRadius() > -200) {
            spy[6] = -spy[6];
            b[6] = b[6] + 1;
        }
        if (b[6] > 8) {
            r[6].setPosition(-1000, -1000);
            spy[6] = 0;
            spx[6] = 0;
            b[6] = 0;
        }
        if (r[7].getPosition().x + r[7].getRadius() > WX && r[7].getPosition().x + r[7].getRadius() < (WX + 200) || r[7].getPosition().x - r[7].getRadius() < 0 && r[7].getPosition().x - r[7].getRadius() > -200){
            spx[7] = -spx[7];
            b[7] = b[7] + 1;
        }
        if (r[7].getPosition().y + r[7].getRadius() > WY && r[7].getPosition().y + r[7].getRadius() < (WY + 200) || r[7].getPosition().y - r[7].getRadius() < 0 && r[7].getPosition().y - r[7].getRadius() > -200) {
            spy[7] = -spy[7];
            b[7] = b[7] + 1;
        }
        if (b[7] > 8) {
            r[7].setPosition(-1000, -1000);
            spy[7] = 0;
            spx[7] = 0;
            b[7] = 0;
        }
        if (r[8].getPosition().x + r[8].getRadius() > WX && r[8].getPosition().x + r[8].getRadius() < (WX + 200) || r[8].getPosition().x - r[8].getRadius() < 0 && r[8].getPosition().x - r[8].getRadius() > -200){
            spx[8] = -spx[8];
            b[8] = b[8] + 1;
        }
        if (r[8].getPosition().y + r[8].getRadius() > WY && r[8].getPosition().y + r[8].getRadius() < (WY + 200) || r[8].getPosition().y - r[8].getRadius() < 0 && r[8].getPosition().y - r[8].getRadius() > -200) {
            spy[8] = -spy[8];
            b[8] = b[8] + 1;
        }
        if (b[8] > 8) {
            r[8].setPosition(-1000, -1000);
            spy[8] = 0;
            spx[8] = 0;
            b[8] = 0;
        }
        if (r[9].getPosition().x + r[9].getRadius() > WX && r[9].getPosition().x + r[9].getRadius() < (WX + 200) || r[9].getPosition().x - r[9].getRadius() < 0 && r[9].getPosition().x - r[9].getRadius() > -200){
            spx[9] = -spx[9];
            b[9] = b[9] + 1;
        }
        if (r[9].getPosition().y + r[9].getRadius() > WY && r[9].getPosition().y + r[9].getRadius() < (WY + 200) || r[9].getPosition().y - r[9].getRadius() < 0 && r[9].getPosition().y - r[9].getRadius() > -200) {
            spy[9] = -spy[9];
            b[9] = b[9] + 1;
        }
        if (b[9] > 8) {
            r[9].setPosition(-1000, -1000);
            spy[9] = 0;
            spx[9] = 0;
            b[9] = 0;
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
            if (rectangle.getPosition().x > rect[j].getPosition().x && rectangle.getPosition().y - 20 > rect[j].getPosition().y - rect[j].getOrigin().y &&
                                                                               rectangle.getPosition().y + 20 < rect[j].getPosition().y + rect[j].getOrigin().y){
                if (rectangle.getPosition().x - 25 < rect[j].getPosition().x + rect[j].getOrigin().x){
                    rectangle.setPosition(rect[j].getPosition().x + rect[j].getOrigin().x + 25, rectangle.getPosition().y);
                    rectangle_1.setPosition(rect[j].getPosition().x + rect[j].getOrigin().x + 25, rectangle_1.getPosition().y);
                }
            }
            if (rectangle.getPosition().x < rect[j].getPosition().x && rectangle.getPosition().y - 20 > rect[j].getPosition().y - rect[j].getOrigin().y &&
                                                                       rectangle.getPosition().y + 20 < rect[j].getPosition().y + rect[j].getOrigin().y){
                if (rectangle.getPosition().x + 25 < rect[j].getPosition().x - rect[j].getOrigin().x){
                    rectangle.setPosition(rect[j].getPosition().x - rect[j].getOrigin().x - 25, rectangle.getPosition().y);
                    rectangle_1.setPosition(rect[j].getPosition().x - rect[j].getOrigin().x - 25, rectangle_1.getPosition().y);
                }
            }
            if (rectangle.getPosition().y > rect[j].getPosition().y && rectangle.getPosition().x - 20 > rect[j].getPosition().x - rect[j].getOrigin().x &&
                                                                       rectangle.getPosition().x + 20 < rect[j].getPosition().x + rect[j].getOrigin().x){
                if (rectangle.getPosition().y - 25 < rect[j].getPosition().y + rect[j].getOrigin().y){
                    rectangle.setPosition(rect[j].getPosition().y + rect[j].getOrigin().y + 25, rectangle.getPosition().x);
                    rectangle_1.setPosition(rect[j].getPosition().y + rect[j].getOrigin().y + 25, rectangle_1.getPosition().x);
                }
            }
            if (rectangle.getPosition().y < rect[j].getPosition().y && rectangle.getPosition().x - 20 > rect[j].getPosition().x - rect[j].getOrigin().x &&
                                                                       rectangle.getPosition().x + 20 < rect[j].getPosition().x + rect[j].getOrigin().x){
                if (rectangle.getPosition().y + 25 < rect[j].getPosition().y - rect[j].getOrigin().y){
                    rectangle.setPosition(rect[j].getPosition().y - rect[j].getOrigin().y - 25, rectangle.getPosition().x);
                    rectangle_1.setPosition(rect[j].getPosition().y - rect[j].getOrigin().y - 25, rectangle_1.getPosition().x);
                }
            }
            for (int p = 0; p < 10; p++){
                if (rect[j].getPosition().x > r[p].getPosition().x && r[p].getPosition().y > rect[j].getPosition().y - rect[j].getOrigin().y &&
                        r[p].getPosition().y < rect[j].getPosition().y + rect[j].getOrigin().y){
                    if (r[p].getPosition().x + r[p].getRadius() > rect[j].getPosition().x - rect[j].getOrigin().x)
                        spx[p] = -spx[p];
                }
                if (rect[j].getPosition().x < r[p].getPosition().x && r[p].getPosition().y > rect[j].getPosition().y - rect[j].getOrigin().y &&
                    r[p].getPosition().y < rect[j].getPosition().y + rect[j].getOrigin().y){
                    if (r[p].getPosition().x - r[p].getRadius() < rect[j].getPosition().x + rect[j].getOrigin().x)
                        spx[p] = -spx[p];
                }
                if (rect[j].getPosition().y > r[p].getPosition().y && r[p].getPosition().x > rect[j].getPosition().x - rect[j].getOrigin().x &&
                    r[p].getPosition().x < rect[j].getPosition().x + rect[j].getOrigin().x){
                    if (r[p].getPosition().y + r[p].getRadius() > rect[j].getPosition().y - rect[j].getOrigin().y)
                        spy[p] = -spy[p];
                }
                if (rect[j].getPosition().y < r[p].getPosition().y && r[p].getPosition().x > rect[j].getPosition().x - rect[j].getOrigin().x &&
                    r[p].getPosition().x < rect[j].getPosition().x + rect[j].getOrigin().x){
                    if (r[p].getPosition().y - r[p].getRadius() < rect[j].getPosition().y + rect[j].getOrigin().y)
                        spy[p] = -spy[p];
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
            kol_prep = random(3, 7);
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
            circle8.setPosition(-1000, -1000);
            stop = 100;
        }



        window.clear(sf::Color(230, 230,250));
        window.draw(big1);
        window.draw(big2);
        window.draw(r[0]);
        window.draw(r[1]);
        window.draw(r[2]);
        window.draw(r[3]);
        window.draw(r[4]);
        window.draw(r[5]);
        window.draw(r[6]);
        window.draw(r[7]);
        window.draw(r[8]);
        window.draw(r[9]);
        window.draw(rectangle);
        window.draw(rectangle_1);
        window.draw(rr);
        window.draw(rr1);
        window.draw(circle8);
        window.draw(rect[0]);
        window.draw(rect[1]);
        window.draw(rect[2]);
        window.draw(rect[3]);
        window.draw(rect[4]);
        window.draw(rect[5]);
        window.draw(rect[6]);
        window.draw(rect[7]);
        window.draw(rect[8]);
        window.draw(rect[9]);
        window.draw(borders[0]);
        window.draw(borders[1]);
        window.draw(borders[2]);
        window.draw(borders[3]);
        window.draw(borders[4]);
        window.draw(borders[5]);
        window.draw(borders[6]);
        window.draw(borders[7]);
        window.display();
    }
    return 0;
}