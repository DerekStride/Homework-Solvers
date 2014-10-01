/**
*   A vector class to represent 3D vectors in space
*
*@author Derek Stride
*@version 0.1
**/

public class Vector3D{
    
    private double i, j, k, magnitude, horizontalAngle, verticalAngle;
    
    
    /**
     * Creates a vector with specified components and calculates the magnitude and angles. The Angles are measured in Radians.
     */
    public Vector3D(double i,double j,double k){
        this.i = i;
        this.j = j;
        this.k = k;
        
        this.magnitude = Math.sqrt(Math.pow(i, 2) + Math.pow(j, 2) + Math.pow(k, 2));
        
        this.horizontalAngle = Math.atan(j / i);
        this.verticalAngle = Math.atan(j / k);
    }
    
    public Vector3D(Vector3D v){
        this(v.i, v.j, v.k);
    }
    
    /**
     * Returns the addition of the parameter and the instance of the vector the method was invoked on.
     */
    public Vector3D add(Vector3D v){
        return new Vector3D(this.i + v.i, this.j + v.j, this.k + v.k);
        
    }
    
    /**
     * Returns the cross product of the parameter and the instance of the vector the method was invoked on.
     */
    public Vector3D cross(Vector3D v){
        double i = (this.j * v.k) - (this.k * v.j);
        double j = (this.k * v.i) - (this.i * v.k);
        double k = (this.i * v.j) - (this.j * v.i);
        return new Vector3D(i, j, k);
    }
    
    /**
     * Returns the dot product of the parameter and the instance of the vector the method was invoked on.
     */
    public double dot(Vector3D v){
        return (this.i * v.i) + (this.j * v.j) + (this.k * v.k);
    }
    
    /**
     * Returns the unit vector of the instance of the vector the method was invoked on.
     */
    public Vector3D unitVector3D(){
        double i = this.i / this.magnitude;
        double j = this.j / this.magnitude;
        double k = this.k / this.magnitude;
        return new Vector3D(i, j, k);
    }
    
    /**
     * Returns the vector of v projected along the vector the method was involked on.
     */
    public Vector3D vectorProjection(Vector3D v){
        return (this.unitVector3D()).mul(v);
    }
    
    /**
     * Returns the triple scalar product in the form of u.rxf
     */
    public double tripleScalarProduct(Vector3D r, Vector3D f){
        return (this.unitVector3D()).dot(r.cross(f));
    }
    
    
    public String toString(){
        return this.i +"i + " + this.j + "j + " + this.k + "k";
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
    public double getMagnitude(){
        return magnitude;
    }
    public double getHorizontalAngle(){
        return horizontalAngle;
    }
    public double getVerticalAngle(){
        return verticalAngle;
    }
    private Vector3D mul(Vector3D v){
        return new Vector3D(this.i * v.i, this.j * v.j, this.k * v.k);
    }
    private Vector3D mul(double v){
        return new Vector3D(this.i * v, this.j * v, this.k * v);
    }
    
}