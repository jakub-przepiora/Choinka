#include "head.h"


CRoundendedLine::CRoundendedLine(const sf::Vector2f& endPoint, const float width)
    : m_endPoint(endPoint), m_Width(width)
{
    update();
}

void CRoundendedLine::setEndPoint(const sf::Vector2f& endPoint)
{
    m_endPoint = endPoint;
    update();
}

void CRoundendedLine::setWidth(const float width)
{
    m_Width = width;
    update();
}

size_t CRoundendedLine::getPointCount() const
{
    return 30;
}

sf::Vector2f CRoundendedLine::getPoint(size_t index) const
{
    sf::Vector2f P1(1.0, 0.0);
    sf::Vector2f P2(m_endPoint + sf::Vector2f(1.0, 0.0) - getPosition());

    sf::Vector2f offset;
    int iFlipDirection;

    if (index < 15)
    {
        offset = P2;
        iFlipDirection = 1;
    }
    else
    {
        offset = P1;
        iFlipDirection = -1;
        index -= 15;
    }

    float start = -atan2(P1.y - P2.y, P2.x - P1.x);
    float M_PI = 3.14;
    float angle = index * M_PI / 14 - M_PI / 2 + start;
    float x = std::cos(angle) * m_Width / 2;
    float y = std::sin(angle) * m_Width / 2;

    return sf::Vector2f(offset.x + x * iFlipDirection, offset.y + y * iFlipDirection);
}
bool wait = false;
bool playing = true;

class Snake {
    public:
        
        int moveSide = 2;        
};
void moveSnake(int side, sf::Sprite &snake, sf::Texture &headSide, int score) {
    int scoreV;
    if (score == 0)
        scoreV = 1;
    else
        scoreV = score;
    int timeout = scoreV + 25;
    switch (side) {
        case 1: {
            sf::Texture headR;
            int pxMove = timeout - 2 * timeout;
            
            snake.move(pxMove, 0);
            break;
        }
 
        case 2: {
            sf::Texture headR;
           
           
            snake.move(timeout, 0);
            break;
        }

        case 3: {
            sf::Texture headR;
            
            
            int pxMoveL = timeout - 2 * timeout;
            snake.move(0, pxMoveL);
            break;
        }

        case 4: {
            sf::Texture headR;
            
            snake.move(0, timeout);
            break;
        }
    }
    Sleep(50);
}

int main()
{


    Snake snake;
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Snake Christmas!");
   
  /*  sf::SoundBuffer mussic;
    sf::Sound sound;
    if (!mussic.loadFromFile("assets/jinglebells.ogg"))
        std::cout << "error";
    sound.setBuffer(mussic);
    sound.play();*/

    sf::Texture bg;
    bg.loadFromFile("assets/snow.jpg");
    sf::Sprite bgh;
    sf::Vector2u size = bg.getSize();
    bgh.setTexture(bg);


    sf::Texture textureHead;
    textureHead.loadFromFile("assets/head.png");
  
 
    CRoundendedLine RoundendedLine;
    RoundendedLine.setPosition(0, 1000);
    RoundendedLine.setEndPoint(sf::Vector2f(0, 0));
    RoundendedLine.setWidth(10);
    RoundendedLine.setFillColor(sf::Color(sf::Color::Green));

    CRoundendedLine RoundendedLine2;
    RoundendedLine2.setPosition(1000, 1000);
    RoundendedLine2.setEndPoint(sf::Vector2f(1000, 0));
    RoundendedLine2.setWidth(10);
    RoundendedLine2.setFillColor(sf::Color(sf::Color::Green));

    CRoundendedLine RoundendedLine3;
    RoundendedLine3.setPosition(1000, 0);
    RoundendedLine3.setEndPoint(sf::Vector2f(1000, 1000));
    RoundendedLine3.setWidth(10);
    RoundendedLine3.setFillColor(sf::Color(sf::Color::Green));

    RoundendedLine3.rotate(90.f);
      
    CRoundendedLine RoundendedLine4;
    RoundendedLine4.setPosition(0, 1000);
    RoundendedLine4.setEndPoint(sf::Vector2f(1000, 1000));
    RoundendedLine4.setWidth(10);
    RoundendedLine4.setFillColor(sf::Color(sf::Color::Green));

    
  
    //SCORING
    int score = 0;
    int checkScore = score;
    //|||||||||||||||||||||||||||||||||||

    sf::Sprite sprites;
    sprites.setTexture(textureHead);
    sprites.setPosition(500, 500);
    //GIFT
    float pointX = ((std::rand() % 1000) + 1);
    float pointY = ((std::rand() % 1000) + 1);
    sf::Texture gift;
    gift.loadFromFile("assets/gift.png");
    sf::Sprite giftPoint;
    giftPoint.setPosition(pointX, pointY);
    giftPoint.setTexture(gift);
    //std::cout << "rendered: X= " << pointX << " Y= " << pointY << " ";
    //ANTYGIFT
   /*
    float antypointX = ((std::rand() % 1000) + 1);
    float antypointY = ((std::rand() % 1000) + 1);
    sf::Texture antygift;
    antygift.loadFromFile("assets/antygift.png");
    sf::Sprite antygiftPoint;
    antygiftPoint.setPosition(antypointX, antypointY);
    antygiftPoint.setTexture(antygift);*/
    //|||||||||||||||||||||||||||||||||||
    bool start = false;
    bool restart = false;
    
    snake.moveSide; //start sidemove
    do{
        restart = false;
        //|||||||||||||||||| DRAW SECTION |||||||||||||||||||||||||||||||||
        window.clear();
        window.draw(bgh);
        window.draw(sprites);
        window.draw(RoundendedLine);
        window.draw(RoundendedLine2);
        window.draw(RoundendedLine3);
        window.draw(RoundendedLine4);
        window.draw(giftPoint);
        //window.draw(antygiftPoint);
        
       
        //|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
        //|||||||||||||||||||||||||||  START  |||||||||||||||||||||||||||||
        if (start == false) {
            sf::Font font;
            font.loadFromFile("assets/arial.ttf");
            sf::Text text("PRESS 'P' to start", font);
            text.setCharacterSize(30);
            text.setStyle(sf::Text::Bold);
            text.setFillColor(sf::Color::Black);
            text.setPosition(400, 400);
            window.draw(text);
        }
        //||||||||||||||||||||||||||||||||||
        else {
            if (playing == false) {
                sf::Font font;
                font.loadFromFile("assets/arial.ttf");

                std::string scoreCurr = std::to_string(score);

                sf::Text text("GAME OVER\n YOUR SCORE: " + scoreCurr, font);
                text.setCharacterSize(30);
                text.setStyle(sf::Text::Bold);
                text.setFillColor(sf::Color::Black);
                text.setPosition(500, 500);
                window.draw(text);
            }

            if (wait == true) {
                sf::Font font;
                font.loadFromFile("assets/arial.ttf");

                std::string scoreCurr = std::to_string(score);

                sf::Text text2("GAME PAUSE\n YOUR SCORE: " + scoreCurr, font);
                text2.setCharacterSize(30);
                text2.setStyle(sf::Text::Bold);
                text2.setFillColor(sf::Color::Red);
                text2.setPosition(500, 500);
                window.draw(text2);
            }
            if (sprites.getGlobalBounds().intersects(RoundendedLine.getGlobalBounds()) == 1 || sprites.getGlobalBounds().intersects(RoundendedLine2.getGlobalBounds()) == 1 || sprites.getGlobalBounds().intersects(RoundendedLine3.getGlobalBounds()) == 1 || sprites.getGlobalBounds().intersects(RoundendedLine4.getGlobalBounds()) == 1) {
                playing = false;
            }
            //SCORE ADD
           
            if (sprites.getGlobalBounds().intersects(giftPoint.getGlobalBounds()) == 1) {
                score++;
                std::string scoreCurr = std::to_string(score);
                std::cout << "\nscore: " << scoreCurr << "\n";

                float pointXNew = ((std::rand() % 900) + 1);
                float pointYNew = ((std::rand() % 900) + 1);
                std::cout << " " << pointYNew << " " << pointXNew;
                giftPoint.setPosition(pointXNew, pointYNew);

                

            }
            //ANTYPOINT
          /*  if (sprites.getGlobalBounds().intersects(antygiftPoint.getGlobalBounds()) == 1) {
                
                float antypointXNew = ((std::rand() % 900) + 1);
                float antypointYNew = ((std::rand() % 900) + 1);
                if (((std::rand() % 10) + 1) % 2 == 0) {
                    std::cout << " :" << antypointYNew << ": " << antypointXNew;
                    antygiftPoint.setPosition(antypointXNew, antypointYNew);
                }
                else {
                    antygiftPoint.setPosition(1200, 1200);
                }
            }*/
            if (!wait && playing)
                moveSnake(snake.moveSide, sprites, textureHead, score);
        }
        
        
        sf::Event event;
        
        while (window.pollEvent(event)) {
            
            switch (event.key.code) {
                
                case sf::Keyboard::Escape:{
                    window.close();
                    break;
                }
                case sf::Keyboard::Left:{
                    
                    //sprites.move(-10, 0);
                    snake.moveSide = 1;

                    break;
                }
                case sf::Keyboard::Right:{
                    
                    //sprites.move(10, 0);
                    snake.moveSide = 2;
                    
                    break;
                }
                case sf::Keyboard::Down:{
               
                    //sprites.move(0, 10);
                    snake.moveSide = 4;
                    break;
                }
                case sf::Keyboard::Up:{
                   
                    //sprites.move(0, -10);
                    snake.moveSide = 3;
                    
                    break;
                }
     
                case sf::Keyboard::Enter: {
                    Sleep(10);
                    std::cout << " STOP ";
                    if(wait == false)
                        wait = true;
                    else
                        wait = false;
                    break;
                    Sleep(10);
                }
                case sf::Keyboard::P:
                    start = true;
                    break;
                case sf::Keyboard::R:
                    restart = true;
                    break;
                default:
                    std::cout << "\nERROOR STOP\n";
           
                    break;
            }
        }
       
        
        
        window.display();
    }while (window.isOpen() && restart == false);

    return 0;
} 

 