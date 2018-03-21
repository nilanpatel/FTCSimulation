package com.malepati.vikas.ftcsimulation.graphics.renderers;

import android.opengl.GLES30;
import android.opengl.GLSurfaceView;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

/**
 * Created by Vikas Malepati on 3/20/2018.
 */

public class Renderer2D implements GLSurfaceView.Renderer {

    public void onSurfaceCreated(GL10 unused, EGLConfig configuration) {
        GLES30.glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    }

    public void onDrawFrame(GL10 unused) {
        GLES30.glClear(GLES30.GL_COLOR_BUFFER_BIT);
    }

    public void onSurfaceChanged(GL10 unused, int width, int height) {
        GLES30.glViewport(0, 0, width, height);
    }

}
