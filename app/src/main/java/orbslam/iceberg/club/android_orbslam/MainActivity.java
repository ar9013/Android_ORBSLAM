package orbslam.iceberg.club.android_orbslam;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

import org.opencv.core.Mat;

public class MainActivity extends Activity {

    private static final String TAG = "MainActivity";
    Mat src;

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("opencv_java"); // 不用額外安裝 opencv app
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */

    public native String stringFromJNI();
}
