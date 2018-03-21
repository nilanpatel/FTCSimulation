package com.malepati.vikas.ftcsimulation.platform.android;

import android.app.Activity;
import android.content.res.AssetManager;
import android.opengl.GLES30;
import android.opengl.GLSurfaceView;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

/**
 * Created by Vikas Malepati on 3/20/2018.
 */

public class AndroidRenderer implements GLSurfaceView.Renderer {

    static {
        System.loadLibrary("FTCSimulation");
    }

    private Activity activity;

    public AndroidRenderer(Activity activity) {
        this.activity = activity;
    }

    public void onSurfaceCreated(GL10 unused, EGLConfig configuration) {
        nativeSurfaceCreate();
    }

    public void onDrawFrame(GL10 unused) {
        nativeRenderFrame();
    }

    public void onSurfaceChanged(GL10 unused, int width, int height) {
        nativeSurfaceChange(width, height);
    }

    public native void nativeSurfaceCreate();

    public native void nativeSurfaceChange(int width, int height);

    public native void nativeRenderFrame();

}
