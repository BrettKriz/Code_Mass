/* ---------------------------------------------------------------- */
/* PROGRAM shm-02-client.c                                          */
/*    This is matching client program of shm-02-server.c            */
/*                                                                  */
/* USE:                                                             */
/*    shm-02-client                                                 */
/* No command line argument is required.                            */
/*                                                                  */
/* NOTE:                                                            */
/*    See shm-02-server.c for the details.                          */
/* ---------------------------------------------------------------- */

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
    pid_t         pid = getpid();
    int           ShmID, i;
    struct Memory *ShmPTR;

    ShmKEY = ftok("./", 'a');
    if ((ShmID = shmget(ShmKEY, sizeof(struct Memory), 0666)) < 0) {
        printf("shmget() failed.\n");
        return 0;
    }
    printf("   Client: Shared memory obtained\n");
    ShmPTR = (struct Memory *) shmat(ShmID, NULL, 0);
    if ((int) ShmPTR == -1) {
        printf("shmat() failed.\n");
        shmctl(ShmID, IPC_RMID, NULL);  /* remove it if shmat() fails */
        return 0;
    }
    printf("   Client: Shared memory attached\n");
    printf("   Client: Shared memory key = %ld\n", ShmKEY);
    printf("   Client: Shared memory ID  = %ld\n", ShmID);
    printf("   Client: My PID = %ld\n", pid);
    printf("   Client: waiting for server's data\n");
    while (ShmPTR->status != FILLED)  /* very busy waiting */
        ;
   
    printf("   Client: retrieving data\n");
    printf("   Client: Server's PID = %ld\n", ShmPTR->data[0]);
    printf("   Client: Data item 1  = %d\n",  ShmPTR->data[1]);
    printf("   Client: Data item 2  = %d\n",  ShmPTR->data[2]);
    printf("   Client: Data item 3  = %d\n",  ShmPTR->data[3]);

    printf("   Client: put its PID back\n");
    ShmPTR->data[0] = pid;
    printf("   Client: Done communication!\n");
    ShmPTR->status  = TAKEN;
    shmdt((void *) ShmPTR);
    return 0;
}

