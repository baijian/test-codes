void Sem_post (sem_t *sem) {
    if (sem_post(sem) == -1) {
        err_says("sem_post error");
    }
}
