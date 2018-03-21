package com.malepati.vikas.ftcsimulation.platform.android;

import android.content.Context;
import android.opengl.GLSurfaceView;

/**
 * Created by Vikas Malepati on 3/20/2018.
 */

public class AndroidContext extends GLSurfaceView {

    public AndroidContext(Context context) {
        super(context);
    }

    public void setRenderer(Renderer renderer) {
        super.setRenderer(renderer);
    }

}
