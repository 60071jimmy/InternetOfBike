/* Author: ChienYu Lin */
/* Date: 2018.02.07 */

#include <assert.h>
#include <stdio.h>
#include "cy_queue.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*(a)))
int main() {
     cy_queue q;
     char a[151] =
          "0123456789"
          "0123456789"
          "0123456789"
          "0123456789"
          "0123456789"
          "0123456789"
          "0123456789"
          "0123456789"
          "0123456789"
          "0123456789"
          "0123456789"
          "0123456789"
          "0123456789"
          "0123456789"
          "0123456789"
          ;
     char x;
     int i;
     int n = ARRAY_SIZE(a) < cy_queue_buf_size ? ARRAY_SIZE(a) : cy_queue_buf_size - 1;
     cy_queue_init(&q);
     assert(cy_queue_is_empty(&q));
     cy_queue_push(&q,'h');
     x = cy_queue_pop(&q);
     assert(x=='h');
     assert(!cy_queue_is_full(&q));
     assert(cy_queue_is_empty(&q));

     for(i = 0; i < 20; ++i) {
          cy_queue_push(&q,a[i]);
          x = cy_queue_pop(&q);
          assert(x == a[i]);
     }
     assert(cy_queue_is_empty(&q));

     for (i = 0; !cy_queue_is_full(&q); ++i) {
          cy_queue_push(&q,a[i]);
     }
     for (i = 0; !cy_queue_is_empty(&q); ++i) {
          x = cy_queue_pop(&q);
          assert(x == a[i]);
     }
     cy_queue_deinit(&q);
     return 0;
}
