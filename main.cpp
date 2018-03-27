#include<graphics.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>
void layout();
float numgen(float num[],int i,int dp);
float add(float number,float num1);
float sub(float number,float num1);
float mul(float number,float num1);
float divi(float number,float num1);
int click();
main()
{
    initwindow(300,370);
    int remark,i,j,k,dp;
    float num[100]={0},number[100]= {0},ans;
    char task;
    task='\0';
    i=0;
    j=0;
    ans=0;
    dp=-1;
    layout();
    setviewport(3,8,290,50,1);
getclick:
    clearmouseclick(513);
    setbkcolor(WHITE);
    clearviewport();
    setcolor(RED);
    settextstyle(2,1,10);
    char c[100];
    if((number[j]==0||number[j]==1)&&j!=0&&i!=1)
    {
        k=j-1;
    }
    else
    {
        k=j;
    }
    if(number[k]-(int)number[k]==0)
    {
        sprintf(c,"%.0f",number[k]);
    }
    else
    {
        sprintf(c,"%.4f",number[k]);
    }
    outtextxy(280,45,c);
    if(task!='S'&&task!='^')
    {
        settextstyle(2,1,6);
        sprintf(c,"%c",task);
        outtextxy(10,25,c);
    }
    delay(500);
    if(ismouseclick(513)==1)
    {
getclick1:
        remark=click();
        if(remark==-1000)
        {
            number[j]=numgen(num,i,dp);
            goto getclick;
        }
        else if(remark==-100)
        {
            return 0;
        }
        else if(remark>=0&&remark<=9)
        {
            if(task=='S')
            {
                j++;
                i=0;
                task='\0';
            }
            num[i]=remark;
            i++;
            number[j]=numgen(num,i,dp);
            clearviewport();
            delay(25);
            goto getclick;
        }
        else if(remark==-1)
        {
            if(i==dp)
            {
                dp=-1;
            }
            i--;
            if(i<0)
            {
                i=0;
            }
            number[j]=numgen(num,i,dp);
            clearviewport();
            delay(25);
            goto getclick;
        }
        else if(remark==-2)
        {
            dp=i;
            //number[j]=numgen(num,i,dp);
            clearviewport();
            delay(25);
            goto getclick;
        }
        //calculate =
        else if(remark==12)
        {
            if(num[0]-(int)num[0]==0)
            {
                number[j]=numgen(num,i,dp);
            }
            else
            {
                number[j]=num[0];
            }
            if(task=='+')
            {
                number[j]=add(number[j-1],number[j]);
            }
            else if(task=='-')
            {
                number[j]=sub(number[j-1],number[j]);
            }
            else if(task=='x')
            {
                number[j]=mul(number[j-1],number[j]);
            }
            else if(task=='/')
            {
                number[j]=divi(number[j-1],number[j]);
            }
              else if(task=='^')
            {
                number[j]=pow(number[j-1],number[j]);
            }
            clearviewport();
            ans=number[j];
            while(1)
            {
                delay(50);
                setbkcolor(WHITE);
                settextstyle(2,1,10);
                if(task=='/'&&number[j]==-1)
                {
                    settextstyle(2,1,8);
                    outtextxy(285,35,"MATH ERROR");
                }
                else if(number[j]-(int)number[j]==0)
                {
                    sprintf(c,"%.0f",number[j]);
                    outtextxy(280,45,c);
                }
                else
                {
                    sprintf(c,"%.4f",number[j]);
                    outtextxy(285,45,c);
                }
                delay(500);
                if(ismouseclick(513))
                {
                    i=0;
                    j=0;
                    number[j]=0;
                    dp=-1;
                    task='\0';
                    clearviewport();
                    delay(50);
                    goto getclick1;

                }
            }
        }
        else if(remark==11)
        {
            if(num[0]-(int)num[0]==0)
            {
                number[j]=numgen(num,i,dp);
            }
            else
            {
                number[j]=num[0];
            }
            if(task=='+')
            {
                number[j]=add(number[j-1],number[j]);
            }
            else if(task=='-')
            {
                number[j]=sub(number[j-1],number[j]);
            }
            else if(task=='x')
            {
                number[j]=mul(number[j-1],number[j]);
            }
            else if(task=='/')
            {
                number[j]=divi(number[j-1],number[j]);
            }
              else if(task=='^')
            {
                number[j]=pow(number[j-1],number[j]);
            }
            j++;
            i=0;
            number[j]=0;
            dp=-1;
            task='+';
            clearviewport();
            delay(25);
            goto getclick;
        }
        else if(remark==13)
        {
            i=0;
            j=0;
            number[j]=0;
            task='\0';
            goto getclick;
        }
        else if(remark==14)
        {
            if(num[0]-(int)num[0]==0)
            {
                number[j]=numgen(num,i,dp);
            }
            else
            {
                number[j]=num[0];
            }
            if(task=='+')
            {
                number[j]=add(number[j-1],number[j]);
            }
            else if(task=='-')
            {
                number[j]=sub(number[j-1],number[j]);
            }
            else if(task=='x')
            {
                number[j]=mul(number[j-1],number[j]);
            }
            else if(task=='/')
            {
                number[j]=divi(number[j-1],number[j]);
            }
              else if(task=='^')
            {
                number[j]=pow(number[j-1],number[j]);
            }
            j++;
            i=0;
            number[j]=0;
            dp=-1;
            task='-';
            clearviewport();
            delay(25);
            goto getclick;
        }
        else if(remark==15)
        {
            if(num[0]-(int)num[0]==0)
            {
                number[j]=numgen(num,i,dp);
            }
            else
            {
                number[j]=num[0];
            }
            if(task=='+')
            {
                number[j]=add(number[j-1],number[j]);
            }
            else if(task=='-')
            {
                number[j]=sub(number[j-1],number[j]);
            }
            else if(task=='x')
            {
                number[j]=mul(number[j-1],number[j]);
            }
            else if(task=='/')
            {
                number[j]=divi(number[j-1],number[j]);
            }
              else if(task=='^')
            {
                number[j]=pow(number[j-1],number[j]);
            }
            j++;
            i=0;
            number[j]=0;
            dp=-1;
            num[i]=0;
            task='x';
            clearviewport();
            delay(25);
            goto getclick;
        }
        else if(remark==16)
        {
            if(num[0]-(int)num[0]==0)
            {
                number[j]=numgen(num,i,dp);
            }
            else
            {
                number[j]=num[0];
            }
            if(task=='+')
            {
                number[j]=add(number[j-1],number[j]);
            }
            else if(task=='-')
            {
                number[j]=sub(number[j-1],number[j]);
            }
            else if(task=='x')
            {
                number[j]=mul(number[j-1],number[j]);
            }
            else if(task=='/')
            {
                number[j]=divi(number[j-1],number[j]);
            }
            else if(task=='^')
            {
                number[j]=pow(number[j-1],number[j]);
            }
            j++;
            i=0;
            number[j]=0;
            dp=-1;
            num[i]=0;
            task='/';
            clearviewport();
            delay(25);
            goto getclick;
        }
        else if(remark==-3)
        {
            number[j]=sqrt(number[j]);
            num[0]=number[j];
            i=1;
            task='S';
            ans=number[j];
            clearviewport();
            delay(50);
            clearmouseclick(513);
            goto getclick;
        }
        else if(remark==-4)
        {
            number[j]=(number[j]/100)*number[j-1];
            if(number[j-1]==0)
            {
                number[j]=0;
            }
            num[0]=number[j];
            i=1;
            task='S';
            ans=number[j];
            clearviewport();
            delay(50);
            clearmouseclick(513);
            goto getclick;
        }
        else if(remark==-5)
        {
            if(num[0]-(int)num[0]==0)
            {
                number[j]=numgen(num,i,dp);
            }
            else
            {
                number[j]=num[0];
            }
            if(task=='+')
            {
                number[j]=add(number[j-1],number[j]);
            }
            else if(task=='-')
            {
                number[j]=sub(number[j-1],number[j]);
            }
            else if(task=='x')
            {
                number[j]=mul(number[j-1],number[j]);
            }
            else if(task=='/')
            {
                number[j]=divi(number[j-1],number[j]);
            }
              else if(task=='^')
            {
                number[j]=pow(number[j-1],number[j]);
            }
            j++;
            i=0;
            number[j]=0;
            dp=-1;
            num[i]=0;
            task='^';
            clearviewport();
            delay(25);
            goto getclick;
        }
        else if(remark==-6)
        {
            number[j]=ans;
            num[0]=ans;
            i=1;
            clearviewport();
            delay(25);
            goto getclick;
        }
        else
        {
            clearmouseclick(513);
            goto getclick;
        }
    }
    clearmouseclick(513);
    goto getclick;
}
int click()
{
    int x,y;
    x=mousex();
    y=mousey();
    if(x>=108&&x<=156&&y>=138&&y<=188)
    {
        clearmouseclick(513);
        return 9;
    }
    else if(x>=56&&x<=104&&y>=138&&y<=188)
    {
        clearmouseclick(513);
        return 8;
    }
    else if(x>=4&&x<=52&&y>=138&&y<=188)
    {
        clearmouseclick(513);
        return 7;
    }
    else if(x>=108&&x<=156&&y>=192&&y<=246)
    {
        clearmouseclick(513);
        return 6;
    }
    else if(x>=56&&x<=104&&y>=192&&y<=246)
    {
        clearmouseclick(513);
        return 5;
    }
    else if(x>=4&&x<=52&&y>=192&&y<=246)
    {
        clearmouseclick(513);
        return 4;
    }
    else if(x>=108&&x<=156&&y>=250&&y<=300)
    {
        clearmouseclick(513);
        return 3;
    }
    else if(x>=56&&x<=104&&y>=250&&y<=300)
    {
        clearmouseclick(513);
        return 2;
    }
    else if(x>=4&&x<=52&&y>=250&&y<=300)
    {
        clearmouseclick(513);
        return 1;
    }
    else if(x>=56&&x<=104&&y>=304&&y<=354)
    {
        clearmouseclick(513);
        return 0;
    }
    else if(x>=4&&x<=52&&y>=304&&y<=354)
    {
        clearmouseclick(513);
        return -2;
    }
    else if(x>=108&&x<=156&&y>=75&&y<=125)
    {
        clearmouseclick(513);
        return -3;
    }
    else if(x>=56&&x<=104&&y>=75&&y<=125)
    {
        clearmouseclick(513);
        return -4;
    }
     else if(x>=4&&x<=52&&y>=75&&y<=125)
    {
        clearmouseclick(513);
        return -5;
    }
    else if(x>=108&&x<=156&&y>=304&&y<=354)
    {
        clearmouseclick(513);
        return -6;
    }
    else if(x>=175&&x<=225&&y>=138&&y<=246)
    {
        clearmouseclick(513);
        return 11;
    }
    else if(x>=200&&x<=254&&y>=304&&y<=354)
    {
        clearmouseclick(513);
        return 12;
    }
    else if(x>=229&&x<=279&&y>=138&&y<=188)
    {
        clearmouseclick(513);
        return 13;
    }
    else if(x>=175&&x<=225&&y>=250&&y<=300)
    {
        clearmouseclick(513);
        return 14;
    }
    else if(x>=229&&x<=279&&y>=192&&y<=246)
    {
        clearmouseclick(513);
        return 15;
    }
    else if(x>=229&&x<=279&&y>=250&&y<=300)
    {
        clearmouseclick(513);
        return 16;
    }
    else if(x>=175&&x<=225&&y>=75&&y<=125)
    {
        clearmouseclick(513);
        return -1;
    }
    else if(x>=230&&x<=280&&y>=75&&y<=125)
    {
        clearmouseclick(513);
        return -100;
    }
    else if(x>=1&&x<=48&&y>=55&&y<=65)
    {
        cleardevice();
        setviewport(0,0,300,370,1);
        setcolor(BLUE);
        settextstyle(8,0,1);
        outtextxy(10,10,"MD. NAHIDUL ISLAM OPU");
        outtextxy(10,50,"opu.nahidul@gmail.com");
        delay(2000);
        cleardevice();
        clearviewport();
        layout();
        setviewport(3,8,290,50,1);
        return -1000;
    }
    clearmouseclick(513);
    return -1000;
}
void layout()
{
    floodfill(0,0,WHITE);
    setbkcolor(WHITE);
    setcolor(BLACK);
    settextstyle(0,0,1);
    outtextxy(1,55,"credit");
    setbkcolor(BLACK);
    rectangle(1,55,48,65);
    rectangle(1,6,291,52);
    //off
    setfillstyle(SOLID_FILL,BLACK);
    bar(230,75,280,125);
    setcolor(RED);
    settextstyle(2,0,6);
    outtextxy(237,90,"OFF");
    //del,squreroot
    setfillstyle(SOLID_FILL,BLACK);
    bar(175,75,225,125);
    bar(108,75,156,125);
    bar(56,75,104,125);
    bar(4,75,52,125);
    setcolor(RED);
    settextstyle(2,0,6);
    outtextxy(182,90,"DEL");
    line(125,90,142,90);
    line(125,90,123,107);
    line(123,107,120,102);
    outtextxy(128,91,"x");
    outtextxy(71,91,"%");
    outtextxy(20,91,"x");
    settextstyle(2,0,4);
    outtextxy(30,87,"n");


    //9,8,7
    setfillstyle(SOLID_FILL,BLACK);
    bar(4,138,52,188);
    bar(56,138,104,188);
    bar(108,138,156,188);
    setcolor(RED);
    settextstyle(2,0,6);
    outtextxy(20,153,"7");
    outtextxy(72,153,"8");
    outtextxy(124,153,"9");
    //6,5,4
    setfillstyle(SOLID_FILL,BLACK);
    bar(4,192,52,246);
    bar(56,192,104,246);
    bar(108,192,156,246);
    setcolor(RED);
    settextstyle(2,0,6);
    outtextxy(20,207,"4");
    outtextxy(72,207,"5");
    outtextxy(124,207,"6");
    //3,2,1
    setfillstyle(SOLID_FILL,BLACK);
    bar(4,250,52,300);
    bar(56,250,104,300);
    bar(108,250,156,300);
    setcolor(RED);
    settextstyle(2,0,6);
    outtextxy(20,265,"1");
    outtextxy(72,265,"2");
    outtextxy(124,265,"3");
    //0
    setfillstyle(SOLID_FILL,BLACK);
    bar(4,304,52,354);
    bar(56,304,104,354);
    bar(108,304,156,354);
    setcolor(RED);
    settextstyle(2,0,6);
    outtextxy(25,315,".");
    outtextxy(72,319,"0");
    outtextxy(114,319,"ANS");
    //+,-
    setfillstyle(SOLID_FILL,BLACK);
    bar(175,138,225,246);
    bar(175,250,225,300);
    setcolor(RED);
    settextstyle(2,0,6);
    outtextxy(195,183,"+");
    outtextxy(195,265,"-");
    //c,*,/
    setfillstyle(SOLID_FILL,BLACK);
    bar(229,138,279,188);
    bar(229,192,279,246);
    bar(229,250,279,300);
    setcolor(RED);
    settextstyle(2,0,6);
    outtextxy(245,153,"C");
    outtextxy(245,207,"X");
    outtextxy(250,265,"/");
    //=
    setfillstyle(SOLID_FILL,BLACK);
    bar(200,304,250,354);
    setcolor(RED);
    settextstyle(2,0,6);
    outtextxy(218,319,"=");
}

float numgen(float num[],int i,int dp)
{
    int l=0;
    float ans=0,ans1=0;
    if(dp==-1)
    {
        while(l<i)
        {
            ans=ans*10+num[l];
            l++;
        }
    }
    else
    {
        while(l<dp)
        {
            ans=ans*10+num[l];
            l++;
        }
        while(l<i)
        {
            ans1=ans1*10+num[l];
            l++;
        }
        ans=ans+ans1/pow(10,i-dp);
    }
    return ans;
}

float add(float number,float num1)
{
    float ans;
    ans=number+num1;
    return ans;
}

float sub(float number,float num1)
{
    float ans;
    ans=number-num1;
    return ans;
}

float mul(float number,float num1)
{
    float ans;
    ans=(number*num1);
    return ans;
}

float divi(float number,float num1)
{
    float ans;
    if(num1==0)
    {
        return -1;
    }
    else
    {
        ans=(number/num1);
        return ans;
    }
}
