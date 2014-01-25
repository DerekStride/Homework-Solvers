#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double deg_rad(double deg)
{
	return deg * M_PI / 180.0;
}

double rad_deg(double rad)
{
	return rad * 180.0 / M_PI;
}

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
	return mag * cos(deg_rad(angle_hor)) * sin(deg_rad(angle_vert));
}

double y_component_3D_2angles(double mag, double angle_hor, double angle_vert)
{
	return mag * sin(deg_rad(angle_hor)) * sin(deg_rad(angle_vert));
}

double z_component_3D_2angles(double mag, double angle_hor, double angle_vert)
{
	return mag * cos(deg_rad(angle_vert));
}

double component_cosines(double mag, double angle)
{
	return mag * cos(deg_rad(angle));
}

double magnitude_mag(double i, double j, double k)
{
	return sqrt(pow(i,2) + pow(j,2) + pow(k, 2));
}

double magnitude_angle(double i, double j)
{
	return rad_deg(atan(j / i)); 
}

double magnitude_2angles(double mag, double angle_horizontal, double angle_vertical)
{
	double ax = x_component_3D_2angles(mag, angle_horizontal, angle_vertical);
	double ay = y_component_3D_2angles(mag, angle_horizontal, angle_vertical);
	double az = z_component_3D_2angles(mag, angle_horizontal, angle_vertical);
	
	return sqrt(pow(ax, 2) + pow(ay, 2) + pow(az, 2));
}

double vertical_angle(double mag, double az)
{
	return rad_deg(acos(az / mag));
}

double horizontal_angle(double mag, double ax, double angle)
{
	return rad_deg(acos(ax / (mag * sin(deg_rad(angle)))));
}

void two_dimensional_vector_calculations()
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

void three_dimensional_vector_calculations()
{
	int input, condition;
	double i1, i2, j1, j2, k1, k2, mag,  angle_hor, angle_vert;
	do {
		printf("Vector 1:\n1 - Enter Components \n2 - Enter magnitude and the horizontal" 
			"& vertical angles\n");
		scanf("%d", &input);
		condition = 0;
		switch (input){
		case 1:
			puts("Enter i component:");
			scanf("%lf", &i1);
			puts("Enter j components:");
			scanf("%lf", &j1);
			puts("Enter k components:");
			scanf("%lf", &k1);
			break;
		case 2:
			puts("Enter magnitude:");
			scanf("%lf", &mag);
			puts("Enter horizontal angle in degrees:");
			scanf("%lf", &angle_hor);
			puts("Enter vertical angle from z axis in degrees:");
			scanf("%lf", &angle_vert);
			i1 = x_component_3D_2angles(mag, angle_hor, angle_vert);
			j1 = y_component_3D_2angles(mag, angle_hor, angle_vert);
			k1 = z_component_3D_2angles(mag, angle_hor, angle_vert);
			break;
		default:
			puts("Try again.");
			condition = 1;
			break;
		}
	} while (condition != 0);
	
	do {
		printf("Vector 2:\n1 - Enter Components \n2 - Enter magnitude and the horizontal" 
			"& vertical angles\n");
		scanf("%d", &input);
		condition = 0;
		switch (input){
		case 1:
			puts("Enter i component:");
			scanf("%lf", &i2);
			puts("Enter j components:");
			scanf("%lf", &j2);
			puts("Enter k components:");
			scanf("%lf", &k2);
			break;
		case 2:
			puts("Enter magnitude:");
			scanf("%lf", &mag);
			puts("Enter horizontal angle in degrees:");
			scanf("%lf", &angle_hor);
			puts("Enter vertical angle from z axis in degrees:");
			scanf("%lf", &angle_vert);
			i2 = x_component_3D_2angles(mag, angle_hor, angle_vert);
			j2 = y_component_3D_2angles(mag, angle_hor, angle_vert);
			k2 = z_component_3D_2angles(mag, angle_hor, angle_vert);
			break;
		default:
			puts("Try again.");
			condition = 1;
			break;
		}
	} while (condition != 0);
	
	double total_i = i1 + i2;
	double total_j = j1 + j2;
	double total_k = k1 + k2;
	mag = magnitude_mag(total_i, total_j, total_k);
	angle_vert = vertical_angle(mag, total_k);
	angle_hor = horizontal_angle(mag, total_i, angle_vert);
	
	printf("The Resulting vector is %.2f i + %.2f j + %.2f k\n", 
		total_i, total_j, total_k);
	printf("The Magnitude is %.2f with an angle of %.2f degrees from the x axis "
		"and %.2f from the z axis\n", 
		mag, angle_hor, angle_vert);
	
	
}




int main(void){
	int input, condition;
	
	do {
		printf("What would you like to do?"
			"\n1 - 2 Dimensional Vector Calculations"
			"\n2 - 3 Dimensional Vector Calculations"
			"\n3 - 3 Dimensional Vector Calculations"
			"\n");
		scanf("%d", &input);
		
		condition = 0;
		
		switch (input){
		case 1:
			two_dimensional_vector_calculations();
			break;
		case 2:
			three_dimensional_vector_calculations();
			break;
		default:
			puts("Try again.");
			condition = 1;
			break;
		}
	}while (condition != 0);
	

	return EXIT_SUCCESS;
}
















