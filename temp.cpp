
while (1) {
    int clone_floor, clone_pos;
    char direction[11];
    scanf("%d%d%s", &clone_floor, &clone_pos, direction);

    if (clone_floor == -1) {
        printf("WAIT\n");
        continue;
    }

    if (clone_floor == exit_floor) {
        if ((clone_pos < exit_pos && strcmp(direction, "LEFT") == 0) || (clone_pos > exit_pos && strcmp(direction, "RIGHT") == 0)) {
            printf("BLOCK\n");
        } else {
            printf("WAIT\n");
        }
    } else {
        if ((clone_pos < elevator_pos[clone_floor] && strcmp(direction, "LEFT") == 0) || (clone_pos > elevator_pos[clone_floor] && strcmp(direction, "RIGHT") == 0)) {
            printf("BLOCK\n");
        } else {
            printf("WAIT\n");
        }
    }
}