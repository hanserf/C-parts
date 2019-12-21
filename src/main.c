#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "ring_buffer.h"

#define BUFSIZE 20

extern int main(void){
    //uint8_t * buffer  = malloc(BUFSIZE * sizeof(uint8_t));
    uint8_t buffer[BUFSIZE];
    cbuf_handle_t cbuf = circular_buf_init(buffer, BUFSIZE);

    /*Fill Buffer*/
    printf("Putting Chars into buffer : \r\n");
    int i;
    uint8_t tmp;
    
    for(i = 0; i < BUFSIZE; i++){
        tmp = 65+i;
        printf("Putting : %c , elements in buffer : %zu \r\n",tmp ,circular_buf_size(cbuf));
        circular_buf_put(cbuf,tmp);
    }
    /*Read Buffer*/
    printf("Reading Chars out of buffer : \r\n");
    for(i = 0; i < BUFSIZE; i++){
        circular_buf_get(cbuf,&tmp);
        printf("Getting : %c , elements in buffer : %zu \r\n",tmp, circular_buf_size(cbuf));
    }

    //free(buffer);
    circular_buf_free(cbuf);
    return 0;
}