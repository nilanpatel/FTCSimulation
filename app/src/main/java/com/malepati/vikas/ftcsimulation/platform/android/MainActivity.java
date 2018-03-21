package com.malepati.vikas.ftcsimulation.platform.android;

import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.os.Bundle;

public class MainActivity extends Activity {

    private GLSurfaceView view;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        view = new AndroidContext(this);
        setContentView(view);

        /* Set OpenGL ES 2.0 Context */
        view.setEGLContextClientVersion(2);

        view.setRenderer(new AndroidRenderer(this));
    }
}
