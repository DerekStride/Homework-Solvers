/**
*	A vector class to represent 3D vectors in space
*
*@name Derek Stride
*@version 0.1
**/

public class Vector{
	
	private double i, j, k, magnitude, horizontalAngle, verticalAngle;
	
	public Vector(double i,double j,double k){
		this.i = i;
		this.j = j;
		this.k = k;
		
		this.magnitude = Math.sqrt(Math.pow(i, 2) + Math.pow(j, 2) + Math.pow(k, 2));
		
		this.horizontalAngle = Math.atan(j / i);
		this.verticalAngle = Math.atan(j / k);
	}
	
	public Vector add(Vector v){
		return new Vector(this.i + v.i, this.j + v.j, this.k + v.k);
		
	}
	
	public double getI(){
		return i;
	}
	public double getJ(){
		return j;
	}
	public double getK(){
		return k;
	}
	
	
}