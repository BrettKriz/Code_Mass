/* ------------------------------------------------------ */
/* PROGRAM shm-01-server.c                                */
/*    This program demonstrates the user of shared memory */
/* It requests a shared memory, fills in some data, and   */
/* waits until the "client" takes the data.  Note that    */
/* busy waiting is used.  This is an inefficient way;     */
/* but so far this is the only method you know.           */
/*                                                        */
/*    Run this program first in a window, and move to     */
/* a second window and run shm-02-client.  Then, you      */
/* should see the "client" prints out the data.           */
/*                                                        */
/* USE:                                                   */
/*    shm-02-server arg1 arg2 arg2                        */
/* arg1, arg2 and arg3 are three integers.                */
/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <sys/types.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>
#include  <unistd.h>

#define   NOT_READY   (-1)
#define   FILLED      (0)
#define   TAKEN       (1)

struct  Memory {
    int  status;
    int  data[4];
};


int  main(int argc, char *argv[])
{
    key_t         ShmKEY;
    int           ShmID, i;
    struct Memory *ShmPTR;

    if (argc != 4) {                   /* check # of arguments      */
        printf("need three integer command line argument.\n");
        return 0;
    }
    ShmKEY = ftok("./", 'a');          /* construct a key           */
    if ((ShmID = shmget(ShmKEY, sizeof(struct Memory), IPC_CREAT|0666)) < 0) {
        printf("shmget() failed.\n");
        return 0;
    }
    printf("Server: Shared memory obtained\n");
    ShmPTR = (struct Memory *) shmat(ShmID, NULL, 0);  /* attachit  */
    if ((long) ShmPTR == -1) {
        printf("shmat() failed.\n");   
        shmctl(ShmID, IPC_RMID, NULL); /* remove it if shmaT fails  */
        return 0;
    }
    printf("Server: Shared memory attached\n");  /* everything ready*/
    printf("Server: Shared memory key = %ld\n", ShmKEY);
    printf("Server: Shared memory ID  = %ld\n", ShmID);
    printf("Server: My PID = %ld\n", getpid());
    printf("Server: Filling data\n");

    ShmPTR->status  = NOT_READY;       /* it is NOT_READY now       */
    ShmPTR->data[0] = getpid();        /* put info in               */
    ShmPTR->data[1] = atoi(argv[1]);
    ShmPTR->data[2] = atoi(argv[2]);
    ShmPTR->data[3] = atoi(argv[3]);

    printf("Server: Data filled and wait\n");
    ShmPTR->status = FILLED;           /* all done & set to FILLED  */
    while (ShmPTR->status != TAKEN)    /* busy waiting here         */
        sleep(1);

    printf("Server: Client has taken the data\n"); /* data taken    */
    printf("Server: Client PID = %ld\n", ShmPTR->data[0]);
    shmdt((void *) ShmPTR);            /* detach shared memory      */
    printf("Server: Shared memory detached\n");
    shmctl(ShmID, IPC_RMID, NULL);     /* remove it                 */
    printf("Server: Shared memory removed\n");
    return 0;
}

