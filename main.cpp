#include<SFML/Graphics.hpp>
#include<time.h>
#include <SFML\Audio.hpp>
#include<sstream>
#include<windows.h>


using namespace sf;using namespace std;

struct point
{
    int x, y;
};
struct point1
{
    int x, y;
}; 
struct point2
{
    int x, y;
}; 
struct point3
{
    int x, y;
};


int main()
{
	int score=0;
	sf::Text scoreText;
	Font font;
	font.loadFromFile("font/font.ttf");
	scoreText.setFont(font);
	scoreText.setString("Hight = 0 ");
	scoreText.setCharacterSize(20);
	scoreText.setFillColor(Color::Red);
	scoreText.setPosition(10,10);
	
	SoundBuffer buffer;
	buffer.loadFromFile("sound/jump.wav");
	Sound sound;
	sound.setBuffer(buffer);
	
	SoundBuffer buffer1;
	buffer1.loadFromFile("sound/namedeadpool.wav");
	Sound sound1;
	sound1.setBuffer(buffer1);
	
	SoundBuffer buffer2;
	buffer2.loadFromFile("sound/loser.wav");
	Sound sound2;
	sound2.setBuffer(buffer2);
	
	SoundBuffer buffer3;
	buffer3.loadFromFile("sound/gamebegin.wav");
	Sound sound3;
	sound3.setBuffer(buffer3);
	
	SoundBuffer buffer4;
	buffer4.loadFromFile("sound/laugh.wav");
	Sound sound4;
	sound4.setBuffer(buffer4);
	
	//game over
	Text gameoverText;
	Texture backgroundTexture1;
	backgroundTexture1.loadFromFile("player/deadpool02.png"); Sprite over(backgroundTexture1);
	gameoverText.setFont(font);
	gameoverText.setString("Game Over!");
	gameoverText.setCharacterSize(80);
	gameoverText.setFillColor(sf::Color::Red);
	RectangleShape gameoverBackground(sf::Vector2f(600, 640));
	gameoverBackground.setFillColor(sf::Color::Black);
	
	
    srand(time(0));

    RenderWindow window(VideoMode(600, 640), "Game");
    window.setFramerateLimit(60);

    Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13;
    t1.loadFromFile("bg/cute1.png");
    t2.loadFromFile("player/platform.png");
    t3.loadFromFile("player/deadpool.png");
    t4.loadFromFile("player/groot.png");
    t5.loadFromFile("bg/bg3.png");
    t6.loadFromFile("player/flash01.png");
    t7.loadFromFile("bg/bg12.png");
    t8.loadFromFile("player/ghot1.png");
    t9.loadFromFile("player/superman02.png");
    t10.loadFromFile("player/base.png");
    t11.loadFromFile("player/thunder.png");
    t12.loadFromFile("player/batman.png");
    t13.loadFromFile("bg/bg6.png");

    Sprite sBackground(t1), sPlat(t2), sPers(t3), wove(t4), xx2(t5), flash(t6), bg(t7), sitem(t8), superman(t9), sdead(t10), sthunder(t11), bg1(t13), batman(t12);

    point plat[10];
    point1 item[1];
    point2 dead[1];
    point3 thunder[1];
    /// enermy01
     for (int i = 0; i < 1; i++)
    {
        item[i].x = rand() % 540;
        item[i].y = rand() % 600;
    }

        //randome plat
    for (int i = 0; i < 10; i++)
    {
        plat[i].x = rand() % 540;
        plat[i].y = rand() % 600;
    }
    
         //enamy02
    for (int i = 0; i < 1; i++)
    {
        dead[i].x = rand() % 540;
        dead[i].y = rand() % 600;
    }
    
         //thunder
     for (int i = 0; i < 1; i++)
    {
        thunder[i].x = rand() % 540;
        thunder[i].y = rand() % 600;
    }

    int x = 100, y = 100, h = 200;
    float dx = 0, dy = 0;

    while (window.isOpen())
    {
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
            {
            	window.close();
		  }                
        }
        if (Keyboard::isKeyPressed(Keyboard::D)) x += 7;
        if (Keyboard::isKeyPressed(Keyboard::A)) x -= 7;
        if (Keyboard::isKeyPressed(Keyboard::S)) dy=0.7;
        if (Keyboard::isKeyPressed(Keyboard::W)) dy=-50;
        if (Keyboard::isKeyPressed(Keyboard::E)) window.draw(superman);
        ////
        if(x>600) x=-80;
        if(x<-80) x=600;
        ////
               
        if(y<h)   //plate put
        {
            for (int i = 0; i < 10; i++)
		   {
                y = h;
                plat[i].y = plat[i].y - dy;
                if (plat[i].y > 640) 
			 { 
			   plat[i].y = 0; 
			   plat[i].x = rand() % 580; 
			 }
             }
             for (int i = 0; i < 2; i++)
		   {
                y = h;
                item[i].y = item[i].y - dy;
                if (item[i].y > 640) 
			 { 
			   item[i].y = 0; 
			   item[i].x = rand() % 580; 
			 }
             }
             for (int i = 0; i < 2; i++)
		   {
                y = h;
                dead[i].y = dead[i].y - dy;
                if (dead[i].y > 640) 
			 { 
			   dead[i].y = 0; 
			   dead[i].x = rand() % 580; 
			 }
             }
             for (int i = 0; i < 2; i++)
		   {
                y = h;
                thunder[i].y = thunder[i].y - dy;
                if (thunder[i].y > 640) 
			 { 
			   thunder[i].y = 0; 
			   thunder[i].x = rand() % 580; 
			 }
	        }
         }
         
         for (int i = 0; i < 1; i++)
          {
        	 if ((x > item[i].x-50) && (x < item[i].x+50 ) && (y  < item[i].y + 50) && (y+80 > item[i].y) )
		    {
		    	//dx=-10;
	/*	    	sound2.play();
			gameoverText.setPosition(90, 20);
			scoreText.setPosition(40, 550);
			over.setPosition(60, 60);
			goto gameover;*/
		    	        
		    }             
	     }
	     	     
	     for (int i = 0; i < 1; i++)
          {
        	 if ((x+80 > dead[i].x) && (x < dead[i].x+50 ) && (y+80  < dead[i].y + 50) && (y+80 > dead[i].y) && (dy > 0))
		    {
		    	dy=-25;
		    }              
	     } 
	     
	     for (int i = 0; i < 1; i++)
          {
        	 if ((x+70 > thunder[i].x) && (x < thunder[i].x+70 ) && (y  < thunder[i].y + 83) && (y + 83 > thunder[i].y) && (dy > 0))
		    {
	           if (Keyboard::isKeyPressed(Keyboard::D)) x += 10;
                if (Keyboard::isKeyPressed(Keyboard::A)) x -= 10;	        
		    }             
	     }
	               
	   	if (y == h && dy < (-5))
		{
			score += 1;
		     std::stringstream ss;
	          ss << "Hight = " << score;    
               scoreText.setString(ss.str());
		}
		
	        
        superman.setPosition(x, y);
        sPers.setPosition(x, y);
        wove.setPosition(x, y);
        flash.setPosition(x, y);
        batman.setPosition(x, y);
        
        
        if(score<500)
        {
        	dy += 0.3;
           y += dy;
        	for (int i = 0; i < 10; i++)
          {
        	 if ((x > plat[i].x-50) && (x < plat[i].x+50 ) && (y + 80 < plat[i].y + 14) && (y + 80 > plat[i].y) && (dy > 0))
		    {
		    	 sound.play();
        	 	 dy = -13;
		    }             
	     }
        	window.draw(sBackground);
	   }
	   
	   if(score>=500 && score<1000)
        {
        	dy += 0.4;
          y += dy;
          for (int i = 0; i < 10; i++)
          {
        	 if ((x > plat[i].x-50) && (x < plat[i].x+50 ) && (y + 80 < plat[i].y + 14) && (y + 80 > plat[i].y) && (dy > 0))
		    {
		    	 sound.play();
        	 	 dy = -15;
		    }           
	     }
        	window.draw(xx2);
	   }
	   
	   if(score>=1000 && score<1500)
        {
        	dy += 0.7;
          y += dy;
          for (int i = 0; i < 10; i++)
          {
        	 if ((x > plat[i].x-50) && (x < plat[i].x+50 ) && (y + 80 < plat[i].y + 14) && (y + 80 > plat[i].y) && (dy > 0))
		    {
		    	 sound.play();
        	 	 dy = -20;
		    }
              
	     }
        	window.draw(bg);
	   }
	   
	   if(score>=1500)
        {
        	dy += 0.7;
          y += dy;
          for (int i = 0; i < 10; i++)
          {
        	 if ((x > plat[i].x-50) && (x < plat[i].x+50 ) && (y + 80 < plat[i].y + 14) && (y + 80 > plat[i].y) && (dy > 0))
		    {
		    	 sound.play();
        	 	 dy = -20;
		    }
              
	     }
        	window.draw(bg1);
	   }

     
        for (int i = 0; i < 10; i++)
        {
            sPlat.setPosition(plat[i].x, plat[i].y);
            window.draw(sPlat);
        }
        
     
	   window.draw(scoreText);
        if(score<500 &&  !Keyboard::isKeyPressed(Keyboard::E))
        {
        	window.draw(sPers);
	   }
	    if(score>=500 && score<1000)
        {
        	window.draw(wove);
	   }
	   if(score>=1000 && score<1500)
	   {
	   	window.draw(flash);
	   }
	    if(score>=1500)
	   {
	   	window.draw(batman);
	   }
        
        if(score==100)
        {
        	sound1.play();
	   }
	   if(score==1)
        {
        	sound3.play();
	   }
	   if(score==300 || score==800 || score==1300 || score==1800 || score==2300)
        {
        	sound4.play();
	   }


	for (int i = 0; i < 2; i++)
        {
            sitem.setPosition(item[i].x, item[i].y);
            window.draw(sitem);
        }
     
	for (int i = 0; i < 2; i++)
        {
            sdead.setPosition(dead[i].x, dead[i].y);
            window.draw(sdead);
        } 
	       	  	   
        window.display();
        
        if (y > 700)
		{
			sound2.play();
			gameoverText.setPosition(90, 20);
			scoreText.setPosition(40, 550);
			over.setPosition(60, 60);
			goto gameover;
		}
	
        
    }
    
     
     gameover:
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();   
		}
		window.draw(gameoverBackground);
		window.draw(over);
		window.draw(gameoverText);
		window.draw(scoreText);
		window.display();
	}
	

    return 0;

   
}

