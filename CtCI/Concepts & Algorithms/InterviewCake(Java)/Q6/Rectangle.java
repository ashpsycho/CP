  public class Rectangle {

    // coordinates of bottom left corner
    int leftX;
    int bottomY;

    // dimensions
    int width;
    int height;

    public Rectangle(int leftX, int bottomY, int width, int height) {
        this.leftX = leftX;
        this.bottomY = bottomY;
        this.width  = width;
        this.height = height;
    }

    public Rectangle() {}

    public String toString() {
        return String.format("(%d, %d, %d, %d)", leftX, bottomY, width, height);
    }

    public Rectangle findIntersection(Rectangle A, Rectangle B){
        int AUpperX=A.leftX+A.width,AUpperY=A.bottomY+A.height;
        int BUpperX=B.leftX+B.width,BUpperY=B.bottomY+B.height;
        int ALowerX=A.leftX,ALowerY=A.bottomY,BLowerX=B.leftX,BLowerY=B.bwottomY;
        int CUpperX = Math.min(AUpperX,BUpperX);
        int CLowerX =Math.max(ALowerX,BLowerX);
        int CUpperY = Math.min(AUpperY,BUpperY);
        int CLowerY =Math.max(ALowerY,BLowerY);
        CUpperX = Math.max(CUpperX,CLowerX);
        CUpperY = Math.max(CUpperY,CLowerY);
        return new Rectangle(CLowerX,CLowerY,CUpperX-CLowerX,CUpperY-CLowerY); 
    }
}