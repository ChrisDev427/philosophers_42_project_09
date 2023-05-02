/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:32:23 by chris             #+#    #+#             */
/*   Updated: 2023/05/01 10:57:18 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
# include <sys/time.h>


int main() {
    struct timeval start_time, end_time;
    long elapsed_time;

    // Mesure le temps de latence de usleep(1000) en microsecondes
    gettimeofday(&start_time, NULL);
    usleep(300000);
    gettimeofday(&end_time, NULL);


    elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_usec - start_time.tv_usec) / 1000;

    printf("Temps d'attente réel: %ld millisecondes\n", elapsed_time);
    return 0;
}