package com.malepati.vikas.ftcsimulation.platform.android;

import android.content.Context;
import android.opengl.GLSurfaceView;

import com.malepati.vikas.ftcsimulation.graphics.renderers.Renderer2D;

/**
 * Created by Vikas Malepati on 3/20/2018.
 */

public class AndroidContext extends GLSurfaceView {

    public static Context context = null;

    private final Renderer2D renderer;

    public AndroidContext(Context context) {
        super(context);

        this.context = context;

        /* Set OpenGL ES 3.0 Context */
        setEGLContextClientVersion(3);

        renderer = new Renderer2D();

        setRenderer(renderer);
    }

}
