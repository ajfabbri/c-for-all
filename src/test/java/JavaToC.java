import net.fabbrication.cforall;

class JavaToC {

    static {
        try {
            System.loadLibrary("libcforall_java");
        } catch (UnsatisfiedLinkError e) {
            System.err.println("Failed to load libcforall. " + e);
            System.err.println("Set your classpath and ensure" +
                    " LD_LIBRARY_PATH can see libcforall_java etc.");
            System.exit(1);
        }
        
    public static void main(String[] args) {

        System.out.println("5 x 10 is " + Double.toString(libcforall.multiply(5.0, 10.0)));
    }
}

// vim: ts=8 et sw=4 sts=4

