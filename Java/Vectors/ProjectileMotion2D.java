
/**
*   A class to solve 2D projectile motion questions
*
*@author Derek Stride
*@version 1.0
**/
public class ProjectileMotion2D
{
    public static final double GRAVITY = -9.81;
    public static final double DEFAULT_INITIAL_TIME = 0;
    public static final double DEFAULT_INITIAL_HEIGHT = 0;
    public static final Coordinate2D DEFAULT_INITIAL_POINT = new Coordinate2D(DEFAULT_INITIAL_TIME, DEFAULT_INITIAL_HEIGHT);
    
    private double initialMagnitude, initialAngle, initialHeight;
    private Vector2D initialVector, finalVector;
    private Coordinate2D initialPoint, maxPoint, finalPoint;

    /**
     * Sets up the problem.
     */
    public ProjectileMotion2D(Vector2D initialVector){
        this.initialVector = initialVector;
        this.initialHeight = DEFAULT_INITIAL_HEIGHT;
        this.initialPoint = DEFAULT_INITIAL_POINT;
        this.initialMagnitude = initialVector.getMagnitude();
        this.initialAngle = initialVector.getAngle();
        this.maxPoint = findMaxPoint();
    }

    private Coordinate2D findMaxPoint(){
        double t = (-1 * initialVector.getY()) / (GRAVITY);
        double y = (initialVector.getY() * t) + (GRAVITY * 0.5 * Math.pow(t, 2));
        return new Coordinate2D(t, y);
    }
    
    

}
