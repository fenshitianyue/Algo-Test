///////////////////////////////////////////////////////
// 创建两个线程，一个打印元音字母，一个打印辅音字母
///////////////////////////////////////////////////////
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

///////////////////////////////////////////////////////
//属于全局变量，放到临界区
char pool[27] = "abcdefghijklmnopqrstuvwxyz";
int index = 0;
int i, j;
///////////////////////////////////////////////////////
pthread_mutex_t mutex;
pthread_cond_t cond;

void* PrintVowels(void* vowels){
  char* array = (char*)vowels; 
  while(1){
    //临界区
    pthread_mutex_lock(&mutex);
    if(index <= 27){
      switch(pool[index]){ //如果pool中当前元素为元音字母，则添加到元音字母数组中
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
          array[i++] = pool[index++];
          break;
      }
      pthread_cond_signal(&cond);
      pthread_mutex_unlock(&mutex);
    }else{
      pthread_mutex_unlock(&mutex);
      break;
    }
    ////////
  }
  return NULL;
}

void* PrintConsonants(void* consonants){
  char* array = (char*)consonants;
  while(1){
    //临界区
    pthread_mutex_lock(&mutex);
    if(index <= 27){
      pthread_cond_wait(&cond, &mutex);
      if(pool[index] != 'a' && pool[index] != 'e' && pool[index] != 'i' && pool[index] != 'o' && pool[index] != 'u'){
        array[j++] = pool[index++];
      }
      ////////
      pthread_mutex_unlock(&mutex);
    }else{
      pthread_mutex_unlock(&mutex);
      break; 
    }
  }
  return NULL;
}

int main() {
  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init(&cond, NULL);

  pthread_t tid1;  //打印元音字母的线程
  pthread_t tid2; //打印辅音字母的线程

  char vowels[6]; //保存元音字母
  char consonantis[22]; //保存辅音字母

  pthread_create(&tid1, NULL, PrintVowels, vowels);
  pthread_create(&tid2, NULL, PrintConsonants, consonantis);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);

  for(int m = 0; m < i; ++m){
    printf("%c ", vowels[m]);
  }
  printf("\n");
  for(int m = 0; m < j; ++m){
    printf("%c ", consonantis[m]);
  }
  printf("\n");

  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&cond);
  return 0;
}

