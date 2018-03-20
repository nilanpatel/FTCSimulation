package com.malepati.vikas.ftcsimulation;

import android.content.Context;
import android.opengl.GLSurfaceView;

/**
 * Created by Vikas Malepati on 3/19/2018.
 */

public class FTCGLSurfaceView extends GLSurfaceView {

    private final FTCGLRenderer renderer;

    public FTCGLSurfaceView(Context context) {
        super(context);

        /* Creating an OpenGL ES 3.0 Context */
        setEGLContextClientVersion(3);

        renderer = new FTCGLRenderer();

        setRenderer(renderer);
    }
}
