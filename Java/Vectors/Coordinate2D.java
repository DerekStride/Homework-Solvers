
/**
 * Represents a 2D cooridnate in space.
 * 
 * @author Derek 
 * @version 1.0
 */
public class Coordinate2D
{
    private double x, y, r, theta;

    /**
     * Creates the coordinate and initializes polar and cartisian values.
     */
    public Coordinate2D(double x, double y){
        this.x = x;
        this.y = y;
        this.r = Math.hypot(x, y);
        this.theta = Math.toDegrees(Math.asin(y/this.r));
    }


    public double getX(){
        return x;
    }
    public double getY(){
        return y;
    }
    public double getR(){
        return r;
    }
    public double getTheta(){
        return theta;
    }
}
