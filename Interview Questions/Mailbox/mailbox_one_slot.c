// Goal : Build a one-slot mailbox 
/*  
  Implement a mailbox that lets a "producer" function send a temperature reading to a "consumer" 
  function, one message at a time, with no buffering. 
*/

#include <stdio.h>
#include <stdbool.h>

typedef struct {
  int temperature;
  bool full; // true = message waiting, false = empty 
} mailbox_t;

mailbox_t mbox = { .temperature = 0, .full = false };

// Your task
// Implement these two functions:
// Returns 0 on success, -1 if the mailbox is already full 
int mailbox_post(mailbox_t *m, int temp);

// Returns 0 on success, -1 if the mailbox is empty 
int mailbox_read(mailbox_t *m, int *out_temp);

int mailbox_post(mailbox_t *m, int temp)
{
  m->temperature = mbox.temperature;
  mbox.temperature = temp;
  m->full = mbox.full;
  mbox.full = true;
  int c = 0;
  c++;
  if((c > 1) && (m->full = true))
  {
    c--;
    return -1;
  }
  else
  {
    return 0;
  }
}

int mailbox_read(mailbox_t *m, int *out_temp)
{
  m->temperature = mbox.temperature;
  mbox.temperature = &out_temp;
  m->full = mbox.full;
  mbox.full = false;
  return mbox.temperature;
}

// Rules to enforce, exactly like a real mailbox:
// 1. mailbox_post must fail if full is already true. Don't overwrite a message that hasn't been read yet.
// 2. mailbox_read must fail if full is false. There's nothing to read.
// 3. A successful mailbox_post sets full = true.
// 4. A successful mailbox_read sets full = false (this is the "lowering the flag" step).
int main(void)
{
  int val;
  /* First post should succeed */
  printf("post 25: %d\n", mailbox_post(&mbox, 25));
  /* Second post before anyone reads should FAIL */
  printf("post 30: %d\n", mailbox_post(&mbox, 30));
  /* Read should succeed and return 25 */
  printf("read: %d, value = %d\n", mailbox_read(&mbox, &val), val);
  /* Second read with nothing waiting should FAIL */
  printf("read again: %d\n", mailbox_read(&mbox, &val));
  return 0;  
}
