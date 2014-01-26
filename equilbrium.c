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

/* returns the magnitude of a vector (pythagorean theorem */

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
 * Requests the input for 2 3 dimensional vectors and stores the values in the variable
 * that the pointer refers to.
 */

void get_three_dimensional_vector(double *i1, double *i2, double *j1, double *j2, 
	double *k1, double *k2)
{
	int input, condition;
	double mag, angle_hor, angle_vert, angle_x, angle_y, angle_z;
	
	do {
		printf("Vector 1:\n1 - Enter Components" 
		"\n2 - Enter magnitude and the horizontal & vertical angles"
		"\n3 - Enter magnitude and the directional cosines"
		"\n");
		scanf("%d", &input);
		condition = 0;
		switch (input){
		case 1:
			puts("Enter i component:");
			scanf("%lf", i1);
			puts("Enter j components:");
			scanf("%lf", j1);
			puts("Enter k components:");
			scanf("%lf", k1);
			break;
		case 2:
			puts("Enter magnitude:");
			scanf("%lf", &mag);
			puts("Enter horizontal angle in degrees:");
			scanf("%lf", &angle_hor);
			puts("Enter vertical angle in degrees:");
			scanf("%lf", &angle_vert);
			*i1 = x_component_3D_2angles(mag, angle_hor, angle_vert);
			*j1 = y_component_3D_2angles(mag, angle_hor, angle_vert);
			*k1 = z_component_3D_2angles(mag, angle_vert);
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
			*i1 = component_cosines(mag, angle_x);
			*j1 = component_cosines(mag, angle_y);
			*k1 = component_cosines(mag, angle_z);
			break;
		default:
			puts("Try again.");
			condition = 1;
			break;
		}
	} while (condition != 0);
	
	do {
		printf("Vector 2:\n1 - Enter Components"
		"\n2 - Enter magnitude and the horizontal & vertical angles"
		"\n3 - Enter magnitude and the directional cosines"
		"\n");
		scanf("%d", &input);
		condition = 0;
		switch (input){
		case 1:
			puts("Enter i component:");
			scanf("%lf", i2);
			puts("Enter j components:");
			scanf("%lf", j2);
			puts("Enter k components:");
			scanf("%lf", k2);
			break;
		case 2:
			puts("Enter magnitude:");
			scanf("%lf", &mag);
			puts("Enter horizontal angle in degrees:");
			scanf("%lf", &angle_hor);
			puts("Enter vertical angle in degrees:");
			scanf("%lf", &angle_vert);
			*i2 = x_component_3D_2angles(mag, angle_hor, angle_vert);
			*j2 = y_component_3D_2angles(mag, angle_hor, angle_vert);
			*k2 = z_component_3D_2angles(mag, angle_vert);
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
			*i2 = component_cosines(mag, angle_x);
			*j2 = component_cosines(mag, angle_y);
			*k2 = component_cosines(mag, angle_z);
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
	int input, condition;
	double i1, i2, j1, j2, mag1, mag2,  angle1, angle2;
	
	do {
		printf("Vector 1:\n1 - Enter Components \n2 - Enter magnitude & angle\n");
		scanf("%d", &input);
		condition = 0;
		switch (input){
		case 1:
			puts("Enter i component:");
			scanf("%lf", &i1);
			puts("Enter j components:");
			scanf("%lf", &j1);
			break;
		case 2:
			puts("Enter magnitude:");
			scanf("%lf", &mag1);
			puts("Enter Angle in degrees:");
			scanf("%lf", &angle1);
			i1 = x_component_2D(mag1, angle1);
			j1 = y_component_2D(mag1, angle1);
			break;
		default:
			puts("Try again.");
			condition = 1;
			break;
		}
	} while (condition != 0);

	do {
		printf("Vector 2:\n1 - Enter Components \n2 - Enter magnitude & angle\n");
		scanf("%d", &input);
		
		condition = 0;
		switch (input){
		case 1:
			puts("Enter i component:");
			scanf("%lf", &i2);
			puts("Enter j components:");
			scanf("%lf", &j2);
			break;
		case 2:
			puts("Enter magnitude:");
			scanf("%lf", &mag2);
			puts("Enter Angle in degrees:");
			scanf("%lf", &angle2);
			i2 = x_component_2D(mag2, angle2);
			j2 = y_component_2D(mag2, angle2);
			break;
		default:
			puts("Try again.");
			condition = 1;
			break;
		}
	} while (condition != 0);

	double total_i = i1 + i2;
	double total_j = j1 + j2;
	
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
	double i1, i2, j1, j2, k1, k2;

	double *I1, *I2, *J1, *J2, *K1, *K2;
	
	I1 = &i1;
	I2 = &i2;
	J1 = &j1;
	J2 = &j2;
	K1 = &k1;
	K2 = &k2;
	
	get_three_dimensional_vector(I1, I2, J1, J2, K1, K2);
	
	double total_i = i1 + i2;
	double total_j = j1 + j2;
	double total_k = k1 + k2;
	
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
	
	get_three_dimensional_vector(I1, I2, J1, J2, K1, K2);
	
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
	
	get_three_dimensional_vector(I1, I2, J1, J2, K1, K2);
	
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

/*
 * Asks what type of operation you would like to do and calls the appropriate function.
 */

int main(void){
	int input, condition;
	
	do {
		printf("What would you like to do?"
			"\n1 - Vector Calculations"
			"\n");
		scanf("%d", &input);
		
		condition = 0;
		
		switch (input){
		case 1:
			vector_operations();
			break;
		default:
			puts("Try again.");
			condition = 1;
			break;
		}
	}while (condition != 0);
	

	return EXIT_SUCCESS;
}
















