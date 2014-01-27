#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Converts a angle in degrees to radians */
double deg_rad(double deg)
{
	return deg * M_PI / 180.0;
}

/* Converts a angle in radians to degrees */
double rad_deg(double rad)
{
	return rad * 180.0 / M_PI;
}

/* Sums up all the values in an array */

double array_sum(double x[], int num)
{
	double sum = 0;
	for (int count = 0; count < num; count++){
		sum = sum + x[count];
	}
	
	return sum;
	
}

/* 
 * The next 5 functions return the x, y, or z components of a vector in either
 * a 2 dimensional or 3 dimensional space
 */
double x_component_2D(double mag, double angle)
{
	return mag * cos(deg_rad(angle));
}

double y_component_2D(double mag, double angle)
{
	return mag * sin(deg_rad(angle));
}

double x_component_3D_2angles(double mag, double angle_hor, double angle_vert)
{
	return x_component_2D(mag, angle_hor) * cos(deg_rad(angle_vert));
}

double y_component_3D_2angles(double mag, double angle_hor, double angle_vert)
{
	return y_component_2D(mag, angle_hor) * cos(deg_rad(angle_vert));
}

double z_component_3D_2angles(double mag, double angle_vert)
{
	return mag * sin(deg_rad(angle_vert));
}

/* Returns the directional cosine component of the vector, it uses the same algorithm as 
 * as the function x_component_2D
 */

double component_cosines(double mag, double angle)
{
	return mag * cos(deg_rad(angle));
}

/* returns the magnitude of a vector (pythagorean theorem) */

double magnitude_mag(double i, double j, double k)
{
	return sqrt(pow(i,2) + pow(j,2) + pow(k, 2));
}

/* returns the angle of a two dimensional vector */

double magnitude_angle(double i, double j)
{
	return rad_deg(atan(j / i)); 
}

/* calculates the vertical angle from the x-y plane */

double vertical_angle(double mag, double az)
{
	return rad_deg(asin(az / mag));
}

/* 
 * calculates the horizontal angle from the x axis using the reflected component of the 
 * original vector in the x-y plane from the vector in 3 dimensional space.
 */

double horizontal_angle(double mag, double ax, double angle)
{
	return rad_deg(acos(ax / (mag * cos(deg_rad(angle)))));
}

/*
 * Requests the input for a 2 dimensional vector and stores the values in the variable
 * that the pointer refers to.
 */

void get_two_dimensional_vector(double *i, double *j, int vector_num)
{
	int input, condition;
	double mag, angle;
	
	do {
		printf("Vector %d:\n1 - Enter Components" 
		"\n2 - Enter magnitude and the angle above the horizontal\n", vector_num);
		scanf("%d", &input);
		condition = 0;
		switch (input){
		case 1:
			puts("Enter i component:");
			scanf("%lf", i);
			puts("Enter j component:");
			scanf("%lf", j);
			break;
		case 2:
			puts("Enter magnitude:");
			scanf("%lf", &mag);
			puts("Enter horizontal angle in degrees:");
			scanf("%lf", &angle);
			*i = x_component_2D(mag, angle);
			*j = y_component_2D(mag, angle);
			break;
		default:
			puts("Try again.");
			condition = 1;
			break;
		}
	} while (condition != 0);
	
}

/*
 * Requests the input for a 3 dimensional vectors and stores the values in the variable
 * that the pointer refers to.
 */

void get_three_dimensional_vector(double *i, double *j,	double *k, int vector_num)
{
	int input, condition;
	double mag, angle_hor, angle_vert, angle_x, angle_y, angle_z;
	
	do {
		printf("Vector %d:\n1 - Enter Components" 
		"\n2 - Enter magnitude and the horizontal & vertical angles"
		"\n3 - Enter magnitude and the directional cosines"
		"\n", vector_num);
		scanf("%d", &input);
		condition = 0;
		switch (input){
		case 1:
			puts("Enter i component:");
			scanf("%lf", i);
			puts("Enter j component:");
			scanf("%lf", j);
			puts("Enter k component:");
			scanf("%lf", k);
			break;
		case 2:
			puts("Enter magnitude:");
			scanf("%lf", &mag);
			puts("Enter horizontal angle in degrees:");
			scanf("%lf", &angle_hor);
			puts("Enter vertical angle in degrees:");
			scanf("%lf", &angle_vert);
			*i = x_component_3D_2angles(mag, angle_hor, angle_vert);
			*j = y_component_3D_2angles(mag, angle_hor, angle_vert);
			*k = z_component_3D_2angles(mag, angle_vert);
			break;
		case 3:
			puts("Enter the magnitude:");
			scanf("%lf", &mag);
			puts("Enter the angle from the x axis:");
			scanf("%lf", &angle_x);
			puts("Enter the angle from the y axis:");
			scanf("%lf", &angle_y);
			puts("Enter the angle from the z axis:");
			scanf("%lf", &angle_z);
			*i = component_cosines(mag, angle_x);
			*j = component_cosines(mag, angle_y);
			*k = component_cosines(mag, angle_z);
			break;
		default:
			puts("Try again.");
			condition = 1;
			break;
		}
	} while (condition != 0);
	
}

/*
 * Requests the input for a 3 dimensional coordinate and stores the values in the 
 * variable that the pointer refers to.
 */

void get_three_dimensional_coordinate(double *x, double *y, double *z, int point)
{
	int input, condition;
	double mag, angle_hor, angle_vert, angle_x, angle_y, angle_z;
	
	do {
		printf("Point %d:\n1 - Enter coordinates" 
		"\n2 - Enter magnitude and the horizontal & vertical angles"
		"\n3 - Enter magnitude and the directional cosines"
		"\n", point);
		scanf("%d", &input);
		condition = 0;
		switch (input){
		case 1:
			puts("Enter x coordinate:");
			scanf("%lf", x);
			puts("Enter y coordinate:");
			scanf("%lf", y);
			puts("Enter z coordinate:");
			scanf("%lf", z);
			break;
		case 2:
			puts("Enter magnitude:");
			scanf("%lf", &mag);
			puts("Enter horizontal angle in degrees:");
			scanf("%lf", &angle_hor);
			puts("Enter vertical angle in degrees:");
			scanf("%lf", &angle_vert);
			*x = x_component_3D_2angles(mag, angle_hor, angle_vert);
			*y = y_component_3D_2angles(mag, angle_hor, angle_vert);
			*z = z_component_3D_2angles(mag, angle_vert);
			break;
		case 3:
			puts("Enter the magnitude:");
			scanf("%lf", &mag);
			puts("Enter the angle from the x axis:");
			scanf("%lf", &angle_x);
			puts("Enter the angle from the y axis:");
			scanf("%lf", &angle_y);
			puts("Enter the angle from the z axis:");
			scanf("%lf", &angle_z);
			*x = component_cosines(mag, angle_x);
			*y = component_cosines(mag, angle_y);
			*z = component_cosines(mag, angle_z);
			break;
		default:
			puts("Try again.");
			condition = 1;
			break;
		}
	} while (condition != 0);
	
}

/*
 * Calculates and outputs the final vector given the components.
 */

void output_result_vector(double i, double j, double k)
{
	double mag = magnitude_mag(i, j, k);
	double angle_vert = vertical_angle(mag, k);
	double angle_hor = horizontal_angle(mag, i, angle_vert);
	double angle_x = rad_deg(acos(i / mag));
	double angle_y = rad_deg(acos(j / mag));
	double angle_z = rad_deg(acos(k / mag));
	
	printf("The Resulting vector is %.2f i + %.2f j + %.2f k\n", i, j, k);
	printf("The Magnitude is %.2f with an angle of %.2f degrees from the x-z plane "
		"and %.2f from the x-y plane\n", mag, angle_hor, angle_vert);
	printf("The Magnitude is %.2f with an angle of %.2f from the x axis, %.2f from the "
		"y axis and %.2f from the z axis.", mag, angle_x, angle_y, angle_z);
}

/*
 * uses basic right triangle trig and the functions above to do vector addition in two
 * dimensions and outputs the resulting vector components and the magnitude and 
 * corresponding angle from the x axis.
 */

void two_dimensional_vector_addition(void)
{

	int num_of_vectors;

	double *I, *J;
	
	puts("How many vectors are there?");
	do {
		scanf("%d", &num_of_vectors);
	}while(num_of_vectors <= 0);
	
	double i[num_of_vectors], j[num_of_vectors];
	
	for (int count = 0; count < num_of_vectors; count++){
		
		I = &i[count];
		J = &j[count];
		
		get_two_dimensional_vector(I, J, count+1);
	}
	
	double total_i = array_sum(i, num_of_vectors);
	double total_j = array_sum(j, num_of_vectors);
	
	printf("The Resulting vector is %.2f i + %.2f j\n", total_i, total_j);
	printf("The Magnitude is %.2f with an angle of %.2f degrees\n", 
		magnitude_mag(total_i, total_j, 0), magnitude_angle(total_i, total_j));
	
}

/*
 * uses basic right triangle trig and the functions above to do vector addition in three
 * dimensions and outputs the resulting vector components and the magnitude and 
 * corresponding angles from the x axis and x-y plane as well as the directional cosines.
 */

void three_dimensional_vector_addition(void)
{

	int num_of_vectors;

	double *I, *J, *K;
	
	puts("How many vectors are there?");
	do {
		scanf("%d", &num_of_vectors);
	}while(num_of_vectors <= 0);
	
	double i[num_of_vectors], j[num_of_vectors], k[num_of_vectors];
	
	for (int count = 0; count < num_of_vectors; count++){
		
		I = &i[count];
		J = &j[count];
		K = &k[count];
		
		get_three_dimensional_vector(I, J, K, count+1);
	}
	
	double total_i = array_sum(i, num_of_vectors);
	double total_j = array_sum(j, num_of_vectors);
	double total_k = array_sum(k, num_of_vectors);
	
	output_result_vector(total_i, total_j, total_k);
	
}

/* Calculates the cross product between 2 Vectors */

void cross_product(void)
{
	double i1, i2, j1, j2, k1, k2;

	double *I1, *I2, *J1, *J2, *K1, *K2;
	
	I1 = &i1;
	I2 = &i2;
	J1 = &j1;
	J2 = &j2;
	K1 = &k1;
	K2 = &k2;
	
	get_three_dimensional_vector(I1, J1, K1, 1);
	get_three_dimensional_vector(I2, J2, K2, 2);
	
	double total_i = (j1 * k2) - (k1 * j2);
	double total_j = (k1 * i2) - (i1 * k2);
	double total_k = (i1 * j2) - (j1 * i2);
	
	output_result_vector(total_i, total_j, total_k);
	
	
}

/* Calculates the Dot product between 2 Vectors */

void dot_product(void)
{
	double i1, i2, j1, j2, k1, k2;

	double *I1, *I2, *J1, *J2, *K1, *K2;
	
	I1 = &i1;
	I2 = &i2;
	J1 = &j1;
	J2 = &j2;
	K1 = &k1;
	K2 = &k2;
	
	get_three_dimensional_vector(I1, J1, K1, 1);
	get_three_dimensional_vector(I2, J2, K2, 2);
	
	double result = i1 * i2 + j1 * j2 + k1 * k2;
	
	printf("The answer is: %.2f\n", result);
}

/*
 * Gives and calls the vector operations currently supported.
 */

void vector_operations(void)
{
	int input, condition;
	
	do {
		printf("What would you like to do?"
		"\n1 - 2D Additions"
		"\n2 - 3D Additions"
		"\n3 - Dot Product"
		"\n4 - Cross Product"
		"\n");
		scanf("%d", &input);
		
		condition = 0;
		
		switch (input){
		case 1:
			two_dimensional_vector_addition();
			break;
		case 2:
			three_dimensional_vector_addition();
			break;
		case 3:
			dot_product();
			break;
		case 4:
			cross_product();
			break;
		default:
			puts("Try again.");
			condition = 1;
			break;
		}
	}while (condition != 0);
}

/* Calculates and outputs the force along a line. */

void force_along_line(void)
{
	double x1, x2, y1, y2, z1, z2, force;

	double *X1, *X2, *Y1, *Y2, *Z1, *Z2;
	
	X1 = &x1;
	X2 = &x2;
	Y1 = &y1;
	Y2 = &y2;
	Z1 = &z1;
	Z2 = &z2;
	
	puts("Enter the magnitude of the Force:");
	scanf("%lf", &force);
	
	get_three_dimensional_coordinate(X1, Y1, Z1, 1);
	get_three_dimensional_coordinate(X2, Y2, Z2, 2);
	
	double total_x = x2 - x1;
	double total_y = y2 - y1;
	double total_z = z2 - z1;
	
	double mag = magnitude_mag(total_x, total_y, total_z);
	
	double x = total_x / mag;
	double y = total_y / mag;
	double z = total_z / mag;
	
	double force_x = force * x;
	double force_y = force * y;
	double force_z = force * z;
	
	output_result_vector(force_x, force_y, force_z);
}

/* 
 * Calculates the total net forces at equilibrium and determines the Tensions in the
 * remaining cords.
 */
 
void equilibrium(void)
{
	double mag, angle1, angle2, tension1, tension2;
	
	puts("Enter the total force the system holds:");
	scanf("%lf", &mag);
	puts("Enter the acute angle from the horizontal to the first supporting force:");
	scanf("%lf", &angle1);
	puts("Enter the acute angle from the horizontal to the second supporting force:");
	scanf("%lf", &angle2);
	
	tension1 = mag / (((cos(deg_rad(angle1)) * sin(deg_rad(angle2))) / 
		cos(deg_rad(angle2))) + sin(deg_rad(angle1)));
	
	double x1 = tension1 * cos(deg_rad(angle1));
	double y1 = tension1 * sin(deg_rad(angle1));
	
	tension2 = tension1 * cos(deg_rad(angle1)) / cos(deg_rad(angle2));
	
	double x2 = tension2 * cos(deg_rad(angle1));
	double y2 = tension2 * sin(deg_rad(angle2));
	
	printf("Force 1: %.2f  %.2f degrees from horizontal or %.2f i + %.2f j\n", 
		tension1, angle1, x1, y1);
	printf("Force 2: %.2f  %.2f degrees from horizontal or %.2f i + %.2f j\n",
		tension2, angle2, x2, y2);
	
}

/*
 * Gives and calls the force operations currently supported.
 */
 
void force_operations(void)
{
	int input, condition;
	
	do {
		printf("What would you like to do?"
		"\n1 - Force along a line"
		"\n2 - Forces at Equilibrium"
		"\n");
		scanf("%d", &input);
		
		condition = 0;
		
		switch (input){
		case 1:
			force_along_line();
			break;
		case 2:
			equilibrium();
			break;
		default:
			puts("Try again.");
			condition = 1;
			break;
		}
	}while (condition != 0);
}

/*
 * Asks what type of operation you would like to do and calls the appropriate function.
 */

int main(void){

	int input, condition;
	
	do {
		printf("What would you like to do?"
			"\n1 - Vector Calculations"
			"\n2 - Force Calculations"
			"\n");
		scanf("%d", &input);
		
		condition = 0;
		
		switch (input){
		case 1:
			vector_operations();
			break;
		case 2:
			force_operations();
			break;
		default:
			puts("Try again.");
			condition = 1;
			break;
		}
	}while (condition != 0);
	
	
	return EXIT_SUCCESS;
}