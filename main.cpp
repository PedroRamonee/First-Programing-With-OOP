#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

using namespace sf;

int main(){

    RenderWindow window(sf::VideoMode(640, 480), "SFML MELHOR QUE SDL!");

    unsigned seed = time(0);

    srand(seed);

    class Bola{

        private:
            
            
            int tempo = 1;
            float tamanho = 25;
            float posx ;
            float posy ;
            int velx = (rand () % 10) - 5, vely = (rand() % 10) - 5;
            CircleShape circulo;


        public:
               
            Bola(RenderWindow *window, Color cor){

                 /*
                    Construtor do Objeto Bola

                        - Define o tamanho das posiçoes X e Y
                        - Define o raio do circulo
                        - Define a cor do circulo
                        - Define a origem do circulo
                        - Define a posição original do circulo
                    

                */
                posx = window->getSize().x / (rand() % 10 + 1);
                posy = window->getSize().y / (rand() % 10 + 1);
                circulo.setRadius(tamanho);
                circulo.setFillColor(cor);
                circulo.setOrigin(tamanho/2, tamanho/2);
                circulo.setPosition(posx, posy);
            }

            
            void render(RenderWindow * window){

                /*
                Retorna void

                  - Desenha o circula na tela
                */

                window->draw(circulo);
            }
            void setFinalPosition(RenderWindow * window){
                
                 /*
                    Retorna void

                       - Define a posição x e y
                       - Caso as posições sejam maiores que o tamanho da tela ou menores de que 0 a velocidade inverte
    
                */

                posx = posx + velx * tempo;
                posy = posy + vely * tempo;

                if(posx > window->getSize().x || posx < 0){
                    
                    velx *= -1;
                }
                 if(posy > window->getSize().y || posy < 0){
                    
                    vely *= -1;
                }
                

                circulo.setPosition(posx, posy);


            }
         
    };

    Bola bola(&window, Color::Red );
    Bola flavio(&window, Color(255,0,255));
    Bola ramonee(&window, Color(255,255,255));
    Bola seta(&window, Color::Yellow);
    Bola erick(&window, Color::Blue);
    Bola MD(&window, Color::Green);

    Event event;

    while(window.isOpen()){


     while (window.pollEvent(event)){
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

    
        }


        bola.setFinalPosition(&window);
        flavio.setFinalPosition(&window);
        ramonee.setFinalPosition(&window);
        seta.setFinalPosition(&window);
        erick.setFinalPosition(&window);
        MD.setFinalPosition(&window);
        window.clear();
        bola.render(&window);
        flavio.render(&window);
        ramonee.render(&window);
        seta.render(&window);
        erick.render(&window);
        MD.render(&window);
        window.display();
       sf::sleep(sf::milliseconds(10.0f));
    }


    return 0;
}