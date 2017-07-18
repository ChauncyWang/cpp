public class CPU {
    private String brand;
    private String vid;

    public native static CPU get();
    public CPU(){}
    public CPU(String id,String b) {
           this.vid = id;
           this.brand = b;
    }
    public void setVID(String vid) {
        this.vid = vid;
    }
    public void setBrand(String brand) {
        this.brand = brand;
    }
    @Override
    public String toString() {
        return "ID:" + vid + "\nBrand:" + brand;
    }
}