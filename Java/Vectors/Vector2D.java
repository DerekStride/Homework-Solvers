/**
*   A vector class to represent 2D vectors in space
*
*@author Derek Stride
*@version 0.1
**/

public class Vector2D{
    
    private double x, y, magnitude, angle;
    
    
    /**
     * Creates a vector with specified magnitude and angle and calculates the components. The Make sure the angle is measured in Degrees.
     */
    public Vector2D(double magnitude, double horizontalAngle){
        this.x = magnitude * Math.cos(Math.toRadians(horizontalAngle));
        this.x = magnitude * Math.sin(Math.toRadians(horizontalAngle));
        this.magnitude = magnitude;
        this.angle = horizontalAngle;
    }
    
    public Vector2D(Vector2D v){
        this(v.magnitude, v.angle);
    }
    
    private Vector2D components(double x, double y){
        double mag = Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2));
        double ang = Math.toDegrees(Math.asin(y / mag));
        return new Vector2D(mag, ang);
    }
    
    /**
     * Returns the addition of the parameter and the instance of the vector the method was invoked on.
     */
    public Vector2D add(Vector2D v){
        return components(this.x + v.x, this.y + v.y);   
    }
    
    /**
     * Returns the cross product of the parameter and the instance of the vector the method was invoked on.
     */
    public Vector3D cross(Vector2D v){
        double k = (this.x * v.y) - (this.y * v.x);
        return new Vector3D(0, 0, k);
    }
    
    /**
     * Returns the dot product of the parameter and the instance of the vector the method was invoked on.
     */
    public double dot(Vector2D v){
        return (this.x * v.x) + (this.y * v.y);
    }
    
    /**
     * Returns the unit vector of the instance of the vector the method was invoked on.
     */
    public Vector2D unitVector2D(){
        double i = this.x / this.magnitude;
        double j = this.y / this.magnitude;
        return components(i, j);
    }
    
    public String toString(){
        return this.magnitude + " " + this.angle + " degrees from the horizontal";
    }
    public double getX(){
        return x;
    }
    public double getY(){
        return y;
    }
    public double getMagnitude(){
        return magnitude;
    }
    public double getAngle(){
        return angle;
    }
    private Vector2D mul(Vector2D v){
        return components(this.x * v.x, this.y * v.y);
    }
    private Vector2D mul(double v){
        return components(this.x * v, this.y * v);
    }
    
}