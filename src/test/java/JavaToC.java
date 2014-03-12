import net.fabbrication.cforall.*;

/**
 * Test / example Java app calling C library.
 * @author Aaron Fabbri 2014
 */
class JavaToC {

    static {
        try {
            System.loadLibrary("cforall_java");
        } catch (UnsatisfiedLinkError e) {
            System.err.println("Failed to load libcforall. " + e);
            System.err.println("Set your classpath and ensure" +
                    " LD_LIBRARY_PATH can see libcforall_java etc.");
            System.exit(1);
        }
    }

    /**
     * How long does it take to call a C function, from java, via
     * SWIG-generated JNI?
     */
    private static void timeSwigJNI() {
        double min = 1e9, max = -1.0, sum = 0;
        final int count = 10000;
        long t1, t2;
        for (int i = 0; i < count; i++) {
            t1 = libcforall.rdtscl();
            t2 = libcforall.rdtscl();

            long delta = t2 - t1;
            if (delta < min) {
                min = delta;
            }
            if (delta > max) {
                max = delta;
            }
            sum += delta;
        }
        double avg = sum / (double)count;

        System.out.println("Time it takes to make Java->C call, in CPU cycles:");
        System.out.println("(min " + Double.toString(min) + ", max " +
                Double.toString(max) + ", avg " + Double.toString(avg) + ")");

        // Convert stats from cycles to usec
        double cycles_usec = libcforall.get_cycles_per_usec();
        avg /= cycles_usec;
        min /= cycles_usec;
        max /= cycles_usec;

        System.out.println("Time it takes to make Java->C call, in usec:");
        System.out.println("(min " + Double.toString(min) + ", max " +
                Double.toString(max) + ", avg " + Double.toString(avg) + ")");
        return;
    }
        
    public static void main(String[] args) {

        long start_cycles = libcforall.rdtscl();
        System.out.println("5 x 10 is " + Double.toString(libcforall.multiply(5.0, 10.0)));
        double cycles_usec = libcforall.get_cycles_per_usec();
        System.out.println("Your machine appears to do " + Double.toString(cycles_usec) +
                " cycles per usec (Mhz).");

        timeSwigJNI();

        System.out.print("Approx. time spent in main(), in usec/seconds: ");
        long end_cycles = libcforall.rdtscl();
        double usec = (end_cycles-start_cycles) / cycles_usec;
        System.out.println(Double.toString(usec) + "/" + Double.toString(usec/10e6));
    }
}

// vim: ts=8 et sw=4 sts=4

