/* Author: ChienYu Lin */

#include "cy_queue.h"

void cy_queue_push(cy_queue * this_, char x) {
    this_->m_data[this_->m_rear] = x;
    ++this_->m_rear;
    this_->m_rear %= cy_queue_buf_size;
}

char cy_queue_pop(cy_queue * this_) {
    char x;
    x = this_->m_data[this_->m_front];
    ++this_->m_front;
    this_->m_front %= cy_queue_buf_size;
    return x;
}

// return the distance from m_front to m_rear
int cy_queue__distance(cy_queue * this_) {
    if (this_->m_front >= this_->m_front) {
        return this_->m_rear - this_->m_front;
    }
    return cy_queue_buf_size - this_->m_rear + this_->m_front;
}

int cy_queue_is_empty(cy_queue * this_) {
    return cy_queue__distance(this_) == 0;
}

int cy_queue_is_full(cy_queue * this_) {
    return cy_queue__distance(this_) == 1;
}

int cy_queue_init(cy_queue * this_) {
    this_->m_front = 0;
    this_->m_rear = 0;
    return 0;
}

int cy_queue_deinit(cy_queue * this_) {
    (void)this_;
    return 0;
}
