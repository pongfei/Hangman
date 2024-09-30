#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<windows.h>
#include <unistd.h>
#include<time.h>
int acs=0;
int weaponm(n);
int weaponm1(n);
int weaponm2(n);
int weaponm3(n);
int weaponm4(n);
void hangman();
void antisyscls(int x);
void draw(int n,int x);
char ans[4][20]= {"Poisoned","Knife","Shotgun","Hammer"};

int acsTan=0;
int timem(n);
int timem1(n);
int timem2(n);
int timem3(n);
int timem4(n);
void times1();
void times2();
void times3();
void times4();
void hangmanTan();
void antisysclsTan(int x);
void drawTan(int n,int x);
int checkansTan(int n);
char ansTan[4][20]= {"Sevenpm","Twelvepm","Quarter to two","Ninepm"};

int acsChris=0;
int killerm(n);
int killerm1(n);
int killerm2(n);
int killerm3(n);
int killerm4(n);
void hangmanChris();
void antisysclsChris(int x);
void drawChris(int n,int x);
char ansChris[4][20]= {"George","Teacher","Jacob","Daniel"};

void type(const char *p)
{
    if (NULL == p)
        return;

    while(*p)
    {
        printf("%c\xDB", *p++); //one char at a time
        Sleep(10);
        printf("\b \b");
        Sleep(10);
    }
    Sleep(1000);
}

int main(int argc, const char *argv[])
{
    char password1[20];
    char password2[20];
    char password3[20];
    char passAns1[] = "q1ezv1cy";
    char passAns2[] = "m1l02828";
    char passAns3[] = "pej89m";
    int num1,num2,num3;
    int y;
    int repeat1;
    int repeat2;
    int repeat3;

    printf("o    o     oo      o     o    oooooo     o       o      oo      o     o \n");
    printf("o    o    o  o     oo    o   o     oo    oo     oo     o  o     ooo   o \n");
    printf("oooooo   oooooo    o o   o   o           o oo oo o    oooooo    o  o  o \n");
    printf("o    o  o      o   o  o  o   o    ooo    o   o   o   o      o   o    oo \n");
    printf("o    o  o      o   o   o o    ooooo      o       o   o      o   o     o \n");
    printf("\n");
    printf("\n");
    printf("       --------------\n");
    printf("       |             |\n");
    printf("       |             |\n");
    printf("       |             @\n");
    printf("       |             |\n");
    printf("       |            /|\\\ \n");
    printf("       |             |  \n");
    printf("       |            / \\\  \n");
    printf("       |\n");
    printf("    ___|__________________\n");
    printf("   |                      |\n");
    printf("   |                      |\n");
    printf("   |______________________|\n");
    printf("\n");

    printf("Press any number to read the rules: \n");
    printf("Press anything else to quit:\n ");
    scanf("%d",&y);

    if(y>=1)
    {
       system("cls");
       type("Hello detective, There has been murders and we need you to solve these case.\n");
       type("We were told that you are the best we have.\n");
       type("Therefore we will make it challenging for you\n");
       type("This is the game of hangman.\n");
       type("You will be given clue(s) to crack each case and for every letter you get it wrong, the man will be slowly hanged..\n");
       type("Let's make sure the blood of that man will not be on your hand!\n");
       type("And every time you guess wrong, the game will restart\n");
       type("Good luck and have fun with the game..detective\n");
    }

    else
    {
        printf("Thank you for playing!\n");
        exit(0);
    }



   do // this is for stage 1
   {
    printf("Press any number to continue to play: \n");
    scanf("%d", &num1);

    repeat1 = 0;

    if(num1>=1)
    {
        weaponm();
        printf("Input password: ");
        scanf("%s",password1);

        if(strcmp(password1,passAns1)==0)
        {
            printf("Correct password. Please proceed to the next level\n");
            repeat1 = repeat1+2;
        }
        else
        {
            printf("Wrong password. Please play again\n");continue;
        }

    }
   }while (repeat1<=1);

    do // this is for stage 2
    {
    printf("Press 1 to continue: \n");
    scanf("%d", &num2);
    repeat2 = 0;


    if(num2>=1)
    {
        timem();
        printf("Input password: ");
        scanf("%s",password2);

        if(strcmp(password2,passAns2)==0)
        {
            printf("Correct password.\n Please proceed to the next level\n ");
            repeat2 = repeat2+1;
        }
        else
        {
            printf("Wrong password. Please play again\n");continue;
        }
    }

    }while (repeat2<=1);

    do // this is for stage 3
    {
        printf("Press 1 to continue to play the last stage: ");
        scanf("%d",&num3);

        repeat3 = 0;

        if(num3>=1)
        {
            killerm();
            printf("Input password: ");
            scanf("%s",password3);


            if(strcmp(password3,passAns3)==0)
            {
                printf("Correct password. You have won the game, thank you for playing!. Here\'s a candy!\n");
                repeat3 = repeat3+3;
            }
            else
            {
                printf("Wrong password. Please play again\n");continue;
            }
        }
    }while(repeat3<=1);

}
int weaponm(n)
{
    int k;
    do{
        srand(time(NULL));
        n = rand()%4+1;
        acs = n;
        if(n==1){

            weaponm1();
        }
        else if(n==2){

            weaponm2();
        }
        else if(n==3){

            weaponm3();
        }
        else if(n==4){

            weaponm4();
        }
        printf("Press 0: to replay this stage\nPress 1 to continue: ");
        scanf("%d",&k);

    }while (k==0);
}

int weaponm1()
{
    hangman(1);
}
int weaponm2()
{
    hangman(2);
}
int weaponm3()
{
    hangman(3);
}
int weaponm4()
{
    hangman(4);
}

void hangman(int j)
{
    char word[20];
    char curr[20];
    char ch;
    int count,i,n,t,m;

    m=acs-1;
    strcpy(word,ans[m]);
    count=0;
    n=strlen(word);
    for(i=0; i<n; i++)
        curr[i]=' ';
    curr[i]='\0';
    do{
        draw(count,acs);
        for(i=0; i<n; i++) {

            if (curr[i] != ' ') printf("%c ",curr[i]);
            else printf("_ ");
        }
        printf("\n");
        if (count==7) {

            printf("===== You Failed ===== \n");
            printf("Would you want to try again?\n");
            count++;
        }
        else if (strcmp(curr,word)==0) {

            printf("***** Correct ***** \n");
            printf("Your password to the next level is 'q1ezv1cy'\n");
            count = 8;
            switch(acs)
            {
                case 1:printf("The envelope glue was *poisoned* and when the man licked the envelope to seal it, he died.\n");break;
                case 2:printf("You are correct the answer is indeed *Knife*\n"); break;
                case 3:printf("It could be a sniper rifle, however *shotgun* would be the correct answer since *there were many wounds on the body*\n");break;
                case 4:printf("This is probably the hardest one but you are correct!\n The murderer used a *hammer* to smash the victims head.\n");break;
            }
        }
        else {

            ch=getch();
            t=0;
            for(i=0; i<n; i++) {

                if (word[i]==ch) {

                    curr[i] = word[i];
                    t=1;
                }
            }
        if(t==0) count++;
        }

    }while (count<=7);
}

void draw(int n,int x)
{
    system("cls");
    antisyscls(x);
    printf("----- \n");
    printf("|   | \n");

    switch(n) {
    case 0 :
        printf("| \n");
        printf("| \n");
        printf("| \n");
        printf("| \n");
        break;

    case 1 :
        printf("|   O\n");
        printf("| \n");
        printf("| \n");
        printf("| \n");
        break;

    case 2:
        printf("|   O \n");
        printf("|  /  \n");
        printf("| \n");
        printf("| \n");
        break;
    case 3:
        printf("|   O \n");
        printf("|  /| \n");
        printf("| \n");
        printf("| \n");
        break;
    case 4:
        printf("|   O  \n");
        printf("|  /|\\ \n");
        printf("| \n");
        printf("| \n");
        break;
    case 5:
        printf("|   O  \n");
        printf("|  /|\\ \n");
        printf("|   |  \n");
        printf("| \n");
        break;

    case 6:
        printf("|   O   \n");
        printf("|  /|\\ \n");
        printf("|   |   \n");
        printf("|  /    \n");
        break;

    case 7:
        printf("|   O   \n");
        printf("|  /|\\ \n");
        printf("|   |   \n");
        printf("|  / \\ \n");
        break;
    }
    printf("| \n");
}
void antisyscls(int x){
    switch (x){
    case 1: printf("You saw a dead body sitting at the table, alone in the locked office.\nHe did not commit suicide and there was no weapons in the room.\n The only clue is a sealed envelope on the desk in front of him.\n");printf("How did he die?\n");break;
    case 2: printf("You found a dead body lying on the floor with a stabbed wound.\nAlongside it is a note saying *My fangs are sometimes painted in red.\nWithout me, flesh will hardly be carved. I am a weapon to be feared.\n");printf("What is the weapon used by the murderer?\n");break;
    case 3: printf("You found a dead body with so many bullet wounds.\nHowever, there were only one shell found on the floor.\n You know this man was definitely killed by a gun but what gun?\nA little hint *it creates the biggest shock*\n");printf("What type of gun did the murderer use?\n");break;
    case 4: printf("You saw a dead body lying on the ground with a lot of blood coming out of his head.\n There's a little note on his hand that says.\n*What has a head can't think but drives?*\n");printf("What weapon kills him?\n");break;
    }
}

int timem(n)
{
    int k;
    do
    {
        srand(time(NULL));
        n = rand()%4+1;
        acsTan = n;
        if(n==1)
        {
            timem1();
        }
        else if(n==2)
        {
            timem2();
        }
        else if(n==3)
        {
            timem3();
        }
        else if(n==4)
        {
            timem4();
        }
        printf("Press 0. to Replay this stage\nPress 1 to continue: \n");
        scanf("%d",&k);

    }
    while (k==0);
}

int timem1()
{
    hangmanTan();
}
int timem2()
{
    hangmanTan();
}
int timem3()
{
    hangmanTan();
}
int timem4()
{
    hangmanTan();
}

void hangmanTan(int j)
{
    char word[20];
    char curr[20];
    char ch;
    int count,i,n,t,m;

    m=acsTan-1;

    strcpy(word,ansTan[m]);
    count=0;
    n=strlen(word);
    for(i=0; i<n; i++)
        curr[i]=' ';
    curr[i]='\0';
    do
    {
        drawTan(count,acsTan);
        for(i=0; i<n; i++)
        {
            if (curr[i] != ' ') printf("%c ",curr[i]);
            else printf("_ ");
        }
        printf("\n");
        if (count==7)
        {

            printf("===== You Failed ===== \n");
            printf("Would you want to try again?\n");
            count++;
        }
        else if (strcmp(curr,word)==0)
        {

            printf("Correct!\nPlease proceed to the next level\n");
            printf("Your password is 'm1l02828' \n");
            count = 8;
        }
        else
        {
            ch=getch();
            t=0;
            for(i=0; i<n; i++)
            {
                if (word[i]==ch)
                {
                    curr[i] = word[i];
                    t=1;
                }
            }
            if(t==0) count++;
        }

    }
    while (count<=7);
}

void drawTan(int n,int x)
{
    system("cls");
    antisysclsTan(x);
    printf("----- \n");
    printf("|   | \n");

    switch(n)
    {
    case 0 :
        printf("| \n");
        printf("| \n");
        printf("| \n");
        printf("| \n");
        break;

    case 1 :
        printf("|   O\n");
        printf("| \n");
        printf("| \n");
        printf("| \n");
        break;

    case 2:
        printf("|   O \n");
        printf("|  /  \n");
        printf("| \n");
        printf("| \n");
        break;
    case 3:
        printf("|   O \n");
        printf("|  /| \n");
        printf("| \n");
        printf("| \n");
        break;
    case 4:
        printf("|   O  \n");
        printf("|  /|\\ \n");
        printf("| \n");
        printf("| \n");
        break;
    case 5:
        printf("|   O  \n");
        printf("|  /|\\ \n");
        printf("|   |  \n");
        printf("| \n");
        break;

    case 6:
        printf("|   O   \n");
        printf("|  /|\\ \n");
        printf("|   |   \n");
        printf("|  /    \n");
        break;

    case 7:
        printf("|   O   \n");
        printf("|  /|\\ \n");
        printf("|   |   \n");
        printf("|  / \\ \n");
        break;
    }
    printf("| \n");
}

void antisysclsTan(int x)
{
    if(x==1)
    {
        times1();
    }
    else if(x==2)
    {
        times2();
    }
    else if(x==3)
    {
        times3();
    }
    else if(x==4)
    {
        times4();
    }
}

void times1()
{
   printf("Hi there, you may or may not wonder who I am, anyway I\'m here to tell you.\n");
   printf("I\'m the guy in the mask in that security camera footage that you guys are investigating on the murder case of E.J. Danny. \n");
   printf("I would be honest with you that I have no motivation on killing him and thus, I\'m not the murderer.\n");
   printf("Danny was my best friend and I am now doing the investigation on my own too.\n");
   printf("However, you may not believe me and for me to gain your trust as I\'m gonna need your help to find the killer, I\'m now contacting you, the NYPD for all the information I know.\n");
   printf("On the 21st of September when Danny died, I was with him in the morning of that day.\n");
   printf("He anxiously called me at 7 in the morning and said he needed my help at his place immediately.\n");
   printf("It\'s gonna take me about an hour to get to his place since I was at my parent\'s on that day but after he called,\n");
   printf("I instantly jumped in my car and drove as fast as I could to get to him and I finally arrived at his place around 8. \n");
   printf("As I knocked on his door and he opened, he looked unnaturally furious and didn\'t let me into his house as usual.\n");
   printf(" After he said that he didn\'t want me there, I got angry and drove back to my place.\n");
   printf("After the incident, one thought was bothering me for several hours,\nit were his last words he said to me before I left were really confusing and the way he delivered it\n");
   printf("was really uncomfortable to hear; I think it\'s a riddle from a third party to me and you as later on that night, he was found dead.\n");
   printf("What he said was \"As opposed to this morning talk, would be an end.\n");
   printf("When you arrived, this soul was descended. But it could be you to learn how it went, and I hope you do, friend.\"\n");
   printf("Please help me crack this so we might find who did this to him.\n");
   printf("\n");

}

void times2()
{
   printf("Around 5 p.m. Wattson J. was found dead in his bedroom in the apartment. We have got a clue for you detective. \n");
   printf("Our witness left the note in his room, he is Mr. Wattson\'s neighbor. Let\'s read the message together\n");
   printf("\"To whoever reading this message, I am not the murderer,\nI left because I\�m afraid to be the next target if I still stay here. I don\'t want to reveal my profile due to my security.\n");
   printf("I don\�t know who is the murderer and I can\�t remember the time. But the moment I heard Mr.\nWattson screamed out loud with pain, my eyes were looking past the clock.\n");
   printf("On the big big clock, it can be seen that there is a time when the minute and hour clocks are exactly between one \n");
   printf("and two that with both hands are stacked on top of one another.\n");
   printf("I hope this could help you regarding the time.\" In this case, the possible time could be around dawn till sunset.\n");
   printf("With clues and evidence, you need to investigate the time Mr. Wattson was murdered.\n");
   printf("\n");

}

void times3()
{
    printf("Hello Mr. Detective, we have got a lot of hard work for you to do. You might have heard the news that our mayor has been assassinated.\n");
    printf("We caught the murderer himself with the mayor\'s corpse. This man is crazy, he believes he is here for all the sins or something.\n");
    printf(" We need more details about this case. He refuses to answer all questions. However, the suspect keeps saying the same thing\n");
    printf("and we have no clue what he's talking about. \�A man gave 10 cents to his wife and 15 cents to his other wife\� he repeated.\n");
    printf("This could be something related to time. Please help us to figure this out.\n");
    printf("\n");
    printf("For this answer, there are 3 words, meaning that there will be 2 spaces. ");
    printf("\n");

}

void times4()
{
    printf(" Hello detective, I\'ve got a lead and it turns out to be a confession letter for the \n");
    printf(" bizar murder case of James. Here it is:  \"I promised you I am not lying. I am an \n");
    printf(" honest man. I work eight to five to earn my living through the day by being a \n");
    printf(" broker and I really do my work hard not to mention that I always need time to relax \n");
    printf(" during the night time by drinking. It was never my intention to have James killed. \n");
    printf(" He was the love of my life who works a night shift in the bar. It was an accident I \n");
    printf(" swear. I was drunk and I guess I must have gotten too aggressive with him when I \n");
    printf(" came back from the bar. He did not want to dance with me and said that my breath\n");
    printf(" smelled bad. This made me furious. I was so overwhelmed and I was angry at him. \n");
    printf(" I had no idea what I was trying to do. I got caught up in the moment. I knew I had \n");
    printf(" to punish him for bad mouthing me for my stinking breath! I punished him as he \n");
    printf(" was about to rest his eyes. You see, he works as a bartender from sunset until \n");
    printf(" sunrise. Therefore, the only time where I could kill him to see all that blood \n");
    printf(" dripping from his head slowly down to his feet and oh boy, did it give me joy, it \n");
    printf(" would be if two hours ago, it was as long after one o\�clock in the afternoon as it \n");
    printf(" was before one o\�clock in the morning, what time would it be now? If you can \n");
    printf(" solve this riddle, I will tell you more clues about the murder and who knows? You \n");
    printf(" might be the hero of this case and you might even find me.\"\n");
    printf("\n");
    printf(" We really need to solve this to find the wricked murderer, detective! We really need \n");
    printf(" to bring about justice to James and his family before this gets out of hand.\n");
    printf("\n");
}

int killerm(n)
{
    int k;
    do{
        srand(time(NULL));
        n = rand()%4+1;
        acsChris = n;
        if(n==1){

            killerm1();
        }
        else if(n==2){

            killerm2();
        }
        else if(n==3){

            killerm3();
        }
        else if(n==4){

            killerm4();
        }
        printf("Press 0. to Replay this stage\nPress 1. to continue: \n");
        scanf("%d",&k);

    }while (k==0);
}

int killerm1()
{
    hangmanChris(1);
}
int killerm2()
{
    hangmanChris(2);
}
int killerm3()
{
    hangmanChris(3);
}
int killerm4()
{
    hangmanChris(4);
}

void hangmanChris(int j)
{
    char word[20];
    char curr[20];
    char ch;
    int count,i,n,t,m;

    m=acsChris-1;
    strcpy(word,ansChris[m]);
    count=0;
    n=strlen(word);
    for(i=0; i<n; i++)
        curr[i]=' ';
    curr[i]='\0';
    do{
        drawChris(count,acsChris);
        for(i=0; i<n; i++) {

            if (curr[i] != ' ') printf("%c ",curr[i]);
            else printf("_ ");
        }
        printf("\n");
        if (count==7) {

            printf("===== You Failed ===== \n");
            printf("Would you want to try again?\n");
            count++;
        }
        else if (strcmp(curr,word)==0) {

            printf("***** Correct ***** \n");
            printf("Your password to complete the game is: 'pej89m' \n");
            switch(acsChris)
            {
                case 1:printf("George is the murderer. He can't walk so he is in a wheelchair which created the parallel tracks\n");break;
                case 2:printf("The Teacher is the murderer. He was holding a mid-year test, but it has only been a week since the school opened.\n"); break;
                case 3:printf("Jacob is the murderer. He told the officers that he ordered one more pint, but there was no alcohol left at the bar.\n");break;
                case 4:printf("Daniel is the murderer. He put poison in the ice which explains why Adison did not die since the ice did not have time to dilute.\n");break;
            }
            count = 8;
        }
        else {

            ch=getch();
            t=0;
            for(i=0; i<n; i++) {

                if (word[i]==ch) {

                    curr[i] = word[i];
                    t=1;
                }
            }
        if(t==0) count++;
        }

    }while (count<=7);
}

void drawChris(int n,int x)
{
    system("cls");
    antisysclsChris(x);
    printf("----- \n");
    printf("|   | \n");

    switch(n) {
    case 0 :
        printf("| \n");
        printf("| \n");
        printf("| \n");
        printf("| \n");
        break;

    case 1 :
        printf("|   O\n");
        printf("| \n");
        printf("| \n");
        printf("| \n");
        break;

    case 2:
        printf("|   O \n");
        printf("|  /  \n");
        printf("| \n");
        printf("| \n");
        break;
    case 3:
        printf("|   O \n");
        printf("|  /| \n");
        printf("| \n");
        printf("| \n");
        break;
    case 4:
        printf("|   O  \n");
        printf("|  /|\\ \n");
        printf("| \n");
        printf("| \n");
        break;
    case 5:
        printf("|   O  \n");
        printf("|  /|\\ \n");
        printf("|   |  \n");
        printf("| \n");
        break;

    case 6:
        printf("|   O   \n");
        printf("|  /|\\ \n");
        printf("|   |   \n");
        printf("|  /    \n");
        break;

    case 7:
        printf("|   O   \n");
        printf("|  /|\\ \n");
        printf("|   |   \n");
        printf("|  / \\ \n");
        break;
    }
    printf("| \n");
}
void antisysclsChris(int x){
    switch (x){
    case 1: printf("There was a friend group of 4 where they all went to the same university and had been friends\nsince highschool. One of them was Ronald. He was a shy person. He wore glasses, had thick\nbushy eyebrows and knobby knees. He was the smartest one out of the other 3 and secretly\nenvied his friend Jack. Jack was built like a football player. He was described as a ladies man\nand had the ability to charm whoever he wanted. George was the third friend in the group. He\nwas born with a disability which prevented him from walking, but that did not stop him from\nbeing the life of the friend group. The last person is Daniel. He was introverted and kept to\nhimself, but with his friend group he was considered extroverted. Their favorite place to hangout\nwas at their local fast food restaurant.\nOne night, it started snowing very heavily. A call was received from a worker at the restaurant\nthe friend group hung out at. A dead body was found at the carpark behind the restaurant. The\ncar park was filled to the brim with snow, and the dead body was discovered to be Jack. There\nwere no footprints at all around the area, but only 2 parallel tracks in the snow that led away\nfrom the crime scene. One of the 3 friends was suspected to be the killer.\n");printf("Who is the murderer?\n");break;
    case 2: printf("A chemistry teacher was murdered in the afternoon during the first week of school. The police\nhad 4 different suspects which were the janitor, teacher, coach, and a student that was\nsupposed to meet the chemistry teacher.\nThe janitor grunted to the officer saying he was mopping the hallway. The teacher told the officer\nhe was holding a mid-year exam with confidence. The coach was teaching basketball in the\ngym saying \"you can ask my students\". The student promised the officer that she was held back\nduring lunch because she had a meeting with the principal.\n");printf("Who killed the chemistry teacher?\n");break;
    case 3: printf("Three close friends went on a night out to a pub close to their university. Clark, Jacob, David,\nand Bruce were at the pub ordering drinks after drinks, enjoying their night. By 2am, all the\nalcohol had just finished and they were all heading home. A few hours later, Bruce was found\ndead, behind the bar. The police arrived and called in the three friends to investigate.\nClark told the police, after saying goodbye to his friends, he went to the bathroom then straight\nhome. Jacob told the police that he ordered one more pint for the night and then walked home.\nDavid told the officers that he went to a food stall a few blocks down from the bar and then headed home.\n");printf("Who murdered Bruce?\n");break;
    case 4: printf("Adison and Carlos went over to Daniel's house for dinner, all of whom were friends. Daniel\nprepared a meal for two of his friends and made them both cocktails with ice. Since Adison\narrived by bike, she was very thirsty and drank the cocktail in one go, while Carlos took his time\nwith the drink. The three of them finished dinner and the two friends were about to head out,\nbut Carlos fell from his chair and dropped dead.\n");printf("Who killed Carlos?\n");break;
    }
}
