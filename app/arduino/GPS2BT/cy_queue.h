/* Author: ChienYu Lin */

#ifndef CY_QUEUE_H_INCLUDED
#define CY_QUEUE_H_INCLUDED

enum {
    cy_queue_buf_size = 128
};

typedef struct cy_queue_tag {
    int m_front;
    int m_rear;
    char m_data[cy_queue_buf_size];
} cy_queue;

void cy_queue_push(cy_queue * this_, char x) ;
char cy_queue_pop(cy_queue * this_) ;
int cy_queue_is_empty(cy_queue * this_) ;
int cy_queue_is_full(cy_queue * this_) ;
int cy_queue_init(cy_queue * this_) ;
int cy_queue_deinit(cy_queue * this_) ;

#endif /* CY_QUEUE_H_INCLUDED */
