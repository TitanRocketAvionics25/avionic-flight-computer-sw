#include <stdio.h>
#include <math.h>
#include <string.h>


typedef struct {
    float state[10]; // State: [px, py, pz, vx, vy, vz, qx, qy, qz, qw]
    float covar[10][10];
    float proc_noise[10][10];
    float meas_noise[7][7];
} EKF;

void normalize_quaternion(float q[4]) {
    float mag = sqrtf(q[0] * q[0] + q[1] * q[1] + q[2] * q[2] + q[3] * q[3]);
    for (int i = 0; i < 4; i++) {
        q[i] /= mag;
    }
}



