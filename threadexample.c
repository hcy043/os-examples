#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 void* myturn()
 {
   for(int i =0;i<8;i++)
   {
     sleep(1);
     printf("myturn thread %d\n",i);
   }
   return NULL;

 }
 void wait()
{
  int i=10;
  while(i<20)
  {
    i++;
    printf("asdasd\n" );
  }
}
 void yourturn()
 {
   for(int i=0;i<3;i++)
   {
     sleep(1);

    printf(" yourturn i %d\n",i );
  }
 }
 int main() {
   pthread_t  newthread;
   void * x;
   int result=pthread_create(&newthread,NULL,&myturn,NULL);
   yourturn();
   //pthread_join(newthread,NULL);//if you commnent this line take wrong answer please careful using threads



   return 0;
 }
