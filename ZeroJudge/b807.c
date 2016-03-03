#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef max
#define max(a, b) ((a) > (b) ? (a) : (b))
#endif
#ifndef min
#define min(a, b) ((a) < (b) ? (a) : (b))
#endif

#define POS_DOUBLE_INF_RAW 0x7ff0000000000000
#define NEG_DOUBLE_INF_RAW 0xfff0000000000000
#define NN 10

const double pos_double_inf;
const double neg_double_inf;
int px, py;

int compare(const void *arg1, const void *arg2) {
	double m1 = *((double*)arg1);
	double m2 = *((double*)arg2);
	double x1 = *((double*)arg1 + 1);
	double x2 = *((double*)arg2 + 1);

	if ((x1 >= px && x2 >= px) || (x1 < px && x2 < px)) {
		if (m1 == m2)
			return 0;
		return m1 < m2 ? 1 : -1;
	}
	return x1 > x2 ? 1 : -1;
}

int compare2(const void *arg1, const void *arg2) {
	return *((int*)arg1) - *((int*)arg2);
}

double area(double x1, double y1, double x2, double y2, double x3, double y3) {
	return fabs((x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1)) / 2;
}

int main(void) {
	int T, R, N, xi, yi, Xi, Yi, i, j, k, GP[NN + 1][4], gp_n, point_n, x, y, horizontal_bottom[NN + 1][3], horizontal_top[NN + 1][3], vertical_left[NN + 1][3], vertical_right[NN + 1][3], edge_n;
	double point[(NN + 1) * 4][3], ans, A, A_tmp, tmp_1, tmp_2, flag_1, flag_2;
	*(unsigned long long*)&pos_double_inf = POS_DOUBLE_INF_RAW;
	*(unsigned long long*)&neg_double_inf = NEG_DOUBLE_INF_RAW;

	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d %d", &R, &px, &py, &N);
		if (N == 0) {
			printf("0.00\n");
		} else {
			gp_n = 1;
			for (i = 0; i < N; i++) {
				scanf("%d %d %d %d", &xi, &yi, &Xi, &Yi);
				GP[gp_n][0] = max(-R, min(xi, Xi)); // left
				GP[gp_n][1] = min( R, max(yi, Yi)); // top
				GP[gp_n][2] = min( R, max(xi, Xi)); // right
				GP[gp_n][3] = max(-R, min(yi, Yi)); // bottom
				if (GP[gp_n][0] < R && GP[gp_n][1] > -R && GP[gp_n][2] > -R && GP[gp_n][3] < R)
					gp_n++;
			}
			if (gp_n == 1) {
				printf("0.00\n");
				continue;
			}

			horizontal_bottom[0][0] = R;
			horizontal_bottom[0][1] = -R;
			horizontal_bottom[0][2] = R;

			horizontal_top[0][0] = -R;
			horizontal_top[0][1] = -R;
			horizontal_top[0][2] = R;

			vertical_left[0][0] = R;
			vertical_left[0][1] = -R;
			vertical_left[0][2] = R;

			vertical_right[0][0] = -R;
			vertical_right[0][1] = -R;
			vertical_right[0][2] = R;

			edge_n = 1;

			for (i = 1; i < gp_n; i++) {
				horizontal_bottom[edge_n][0] = GP[i][3];
				horizontal_bottom[edge_n][1] = GP[i][0];
				horizontal_bottom[edge_n][2] = GP[i][2];

				horizontal_top[edge_n][0] = GP[i][1];
				horizontal_top[edge_n][1] = GP[i][0];
				horizontal_top[edge_n][2] = GP[i][2];

				vertical_left[edge_n][0] = GP[i][0];
				vertical_left[edge_n][1] = GP[i][3];
				vertical_left[edge_n][2] = GP[i][1];

				vertical_right[edge_n][0] = GP[i][2];
				vertical_right[edge_n][1] = GP[i][3];
				vertical_right[edge_n][2] = GP[i][1];

				edge_n++;
			}

			GP[0][0] = -R;
			GP[0][1] = R;
			GP[0][2] = R;
			GP[0][3] = -R;
			
			point_n = 0;
			for (i = 0; i < gp_n; i++) {
				for (j = 0; j < 4; j++) {
					switch (j) {
						case 0: /*left-top*/
							x = GP[i][0];
							y = GP[i][1];
							break;
						case 1: /*left-bottom*/
							x = GP[i][0];
							y = GP[i][3];
							break;
						case 2: /*right-top*/
							x = GP[i][2];
							y = GP[i][1];
							break;
						case 3: /*right-bottom*/
							x = GP[i][2];
							y = GP[i][3];
							break;
					}
					if (x == px) {
						if (y == py)
							continue;
						if (y > py)
							point[point_n][0] = pos_double_inf;
						else
							point[point_n][0] = neg_double_inf;
					} else
						point[point_n][0] = (double)(y - px) / (x - py);
					point[point_n][1] = x;
					point[point_n][2] = y;
					for (k = 0; k < point_n; k++)
						if (point[point_n][0] == point[k][0] && (point[point_n][1] * point[k][1] > 0 && point[point_n][2] * point[k][2] > 0)) {
							point_n--;
							break;
						}
					point_n++;
				}
			}
			qsort((void*)point, point_n, 3 * sizeof(double), compare);
			qsort((void*)horizontal_bottom, edge_n, 3 * sizeof(int), compare2);
			qsort((void*)horizontal_top, edge_n, 3 * sizeof(int), compare2);
			qsort((void*)vertical_left, edge_n, 3 * sizeof(int), compare2);
			qsort((void*)vertical_right, edge_n, 3 * sizeof(int), compare2);

			point[point_n][0] = point[0][0];
			point[point_n][1] = point[0][1];
			point[point_n][2] = point[0][2];

			ans = 4 * R * R;
			for (i = 1; i < gp_n; i++)
				ans -= (GP[i][2] - GP[i][0]) * (GP[i][1] - GP[i][3]);
			for (i = 0; i < point_n; i++) {
				A = 4 * R * R;
				if (point[i][1] > px && point[i + 1][1] > px) {
					A_tmp = 4 * R * R;
					for (j = 0; j < edge_n; j++) {
						if (vertical_left[j][0] >= px) {
							flag_1 = point[i][1] < px ? -1.0 : 1.0;
							flag_2 = point[i + 1][1] < px ? -1.0 : 1.0;
							tmp_1 = (point[i][2] - py) * vertical_left[j][0] * flag_1;
							tmp_2 = (point[i + 1][2] - py) * vertical_left[j][0] * flag_2;
							if ((point[i][1] - px) * vertical_left[j][1] * flag_1 <= tmp_1 && tmp_1 <= (point[i][1] - px) * vertical_left[j][2] *flag_1 &&
								(point[i + 1][1] - px) * vertical_left[j][1] *flag_2 <= tmp_2 && tmp_2 <= (point[i + 1][1] - px) * vertical_left[j][2] * flag_2 &&
								!(vertical_left[j][0] == px && vertical_left[j][1] == py && point[i][2] <= py && point[i + 1][2] <= py) &&
								!(vertical_left[j][0] == px && vertical_left[j][2] == py && point[i][2] >= py && point[i + 1][2] >= py)) {
								A_tmp = area(px, py, vertical_left[j][0], point[i][0] * vertical_left[j][0], vertical_left[j][0], point[i + 1][0] * vertical_left[j][0]);
								break;
							}
						}
					}
					A = min(A, A_tmp);
				}
				if (point[i][1] < px && point[i + 1][1] < px) {
					A_tmp = 4 * R * R;
					for (j = edge_n - 1; j >= 0; j--) {
						if (vertical_right[j][0] <= px) {
							flag_1 = point[i][1] < px ? -1.0 : 1.0;
							flag_2 = point[i + 1][1] < px ? -1.0 : 1.0;
							tmp_1 = (point[i][2] - py) * vertical_right[j][0] * flag_1;
							tmp_2 = (point[i + 1][2] - py) * vertical_right[j][0] * flag_2;
							if ((point[i][1] - px) * vertical_right[j][1] * flag_1 <= tmp_1 && tmp_1 <= (point[i][1] - px) * vertical_right[j][2] * flag_1 &&
								(point[i + 1][1] - px) * vertical_right[j][1] * flag_2 <= tmp_2 && tmp_2 <= (point[i + 1][1] - px) * vertical_right[j][2] * flag_2 &&
								!(vertical_right[j][0] == px && vertical_right[j][1] == py && point[i][2] <= py && point[i + 1][2] <= py) &&
								!(vertical_right[j][0] == px && vertical_right[j][2] == py && point[i][2] >= py && point[i + 1][2] >= py)) {
								A_tmp = area(px, py, vertical_right[j][0], point[i][0] * vertical_right[j][0], vertical_right[j][0], point[i + 1][0] * vertical_right[j][0]);
								break;
							}
						}
					}
					A = min(A, A_tmp);
				}

				if (point[i][2] > py && point[i + 1][2] > py) {
					A_tmp = 4 * R * R;
					for (j = 0; j < edge_n; j++) {
						if (horizontal_bottom[j][0] >= py) {
							flag_1 = point[i][2] < py ? -1.0 : 1.0;
							flag_2 = point[i + 1][2] < py ? -1.0 : 1.0;
							tmp_1 = (point[i][1] - px) * horizontal_bottom[j][0] * flag_1;
							tmp_2 = (point[i + 1][1] - px) * horizontal_bottom[j][0] * flag_2;
							if ((point[i][2] - py) * horizontal_bottom[j][1] * flag_1 <= tmp_1 && tmp_1 <= (point[i][2] - py) * horizontal_bottom[j][2] * flag_1 &&
								(point[i + 1][2] - py) * horizontal_bottom[j][1] * flag_2 <= tmp_2 && tmp_2 <= (point[i + 1][2] - py) * horizontal_bottom[j][2] * flag_2 &&
								!(horizontal_bottom[j][0] == py && horizontal_bottom[j][1] == px && point[i][1] <= px && point[i + 1][1] <= px) &&
								!(horizontal_bottom[j][0] == py && horizontal_bottom[j][2] == px && point[i][1] >= px && point[i + 1][1] >= px)) {
								A_tmp = area(px, py, horizontal_bottom[j][0] / point[i][0], horizontal_bottom[j][0], horizontal_bottom[j][0] / point[i + 1][0], horizontal_bottom[j][0]);
								break;
							}
						}
					}
					A = min(A, A_tmp);
				}
				if (point[i][2] < py && point[i + 1][2] < py) {
					A_tmp = 4 * R * R;
					for (j = edge_n - 1; j >= 0; j--) {
						if (horizontal_top[j][0] <= py) {
							flag_1 = point[i][2] < py ? -1.0 : 1.0;
							flag_2 = point[i + 1][2] < py ? -1.0 : 1.0;
							tmp_1 = (point[i][1] - px) * horizontal_top[j][0] * flag_1;
							tmp_2 = (point[i + 1][1] - px) * horizontal_top[j][0] * flag_2;
							if ((point[i][2] - py) * horizontal_top[j][1] * flag_1 <= tmp_1 && tmp_1 <= (point[i][2] - py) * horizontal_top[j][2] * flag_1&&
								(point[i + 1][2] - py) * horizontal_top[j][1] * flag_2 <= tmp_2 && tmp_2 <= (point[i + 1][2] - py) * horizontal_top[j][2] * flag_2 &&
								!(horizontal_top[j][0] == py && horizontal_top[j][1] == px && point[i][1] <= px && point[i + 1][1] <= px) &&
								!(horizontal_top[j][0] == py && horizontal_top[j][2] == px && point[i][1] >= px && point[i + 1][1] >= px)) {
								A_tmp = area(px, py, horizontal_top[j][0] / point[i][0], horizontal_top[j][0], horizontal_top[j][0] / point[i + 1][0], horizontal_top[j][0]);
								break;
							}
						}
					}
					A = min(A, A_tmp);
				}
				if (A < 4 * R * R) {
					ans -= A;
				}
			}
			printf("%.2f\n", ans);
		}
	}
	return 0;
}
