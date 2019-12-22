#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "ring_buffer.h"

#define BUFSIZE 20

static void read_entire_buffer();

extern int main(void){
    //uint8_t * buffer  = malloc(BUFSIZE * sizeof(uint8_t));
    uint8_t buffer[BUFSIZE];
    cbuf_handle_t cbuf = circular_buf_init(buffer, BUFSIZE);

    /*Fill Buffer*/
    printf("-------------------------------------\r\n");  
    printf("Putting Chars into buffer with put1: \r\n");
    printf("-------------------------------------\r\n");  
    int i;
    uint8_t tmp;
    for(i = 0; i < BUFSIZE+5; i++){
        tmp = 65+i;
        printf("Putting : %c , elements in buffer : %zu \r\n",tmp ,circular_buf_size(cbuf));
        circular_buf_put(cbuf,tmp);
    }
    /*Read Buffer*/
    printf("-------------------------------------\r\n");  
    printf("Reading Chars out of buffer : \r\n");
    printf("-------------------------------------\r\n");  
    read_entire_buffer(cbuf);
    printf("-------------------------------------\r\n");
    printf("Putting Chars into buffer with put2: \r\n");
    printf("-------------------------------------\r\n");

    for(i = 0; i < BUFSIZE+5; i++){
        tmp = 65+i;
        printf("Putting : %c , elements in buffer : %zu \r\n",tmp ,circular_buf_size(cbuf));
        circular_buf_put2(cbuf,tmp);
    }
    printf("-------------------------------------\r\n");  
    printf("Reading Chars out of buffer : \r\n");
    printf("-------------------------------------\r\n");  
    read_entire_buffer(cbuf);
    printf("-------------------------------------\r\n");
    
    //free(buffer);
    circular_buf_free(cbuf);
    return 0;
}

static void read_entire_buffer(cbuf_handle_t cbuf){
    uint8_t tmp;
    while(! circular_buf_empty(cbuf)){
        circular_buf_get(cbuf,&tmp);
        printf("Getting : %c , elements in buffer : %zu \r\n",tmp, circular_buf_size(cbuf));
    }
}
