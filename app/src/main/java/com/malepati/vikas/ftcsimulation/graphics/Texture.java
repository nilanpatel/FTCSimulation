package com.malepati.vikas.ftcsimulation.graphics;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.opengl.GLES30;
import android.opengl.GLUtils;

import com.malepati.vikas.ftcsimulation.platform.android.AndroidContext;

/**
 * Created by Vikas Malepati on 3/20/2018.
 */

public class Texture {

    public enum TextureWrap {
        UNKNOWN,
        CLAMP_TO_EDGE,
        REPEAT,
        MIRRORED_REPEAT
    }

    public enum TextureFilter {
        UNKNOWN,
        LINEAR,
        NEAREST
    }

    public class TextureParameters {
        public TextureWrap wrap;
        public TextureFilter filter;

        public TextureParameters() {
            filter = TextureFilter.LINEAR;
            wrap = TextureWrap.CLAMP_TO_EDGE;
        }

        public TextureParameters(TextureFilter filter, TextureWrap wrap) {
            this.filter = filter;
            this.wrap = wrap;
        }
    }

    private TextureParameters parameters;

    private int resource;
    private String name;
    private int handle;
    private int width, height;

    public Texture(int width, int height, TextureParameters parameters) {
        this.resource = -1;
        this.width = width;
        this.height = height;
        this.parameters = parameters;
        this.handle = load();
    }

    public Texture(int width, int height, long color, TextureParameters parameters) {
        this.resource = -1;
        this.width = width;
        this.height = height;
        this.parameters = parameters;
        this.handle = load();

        setData(color);
    }

    public Texture(String name, int resource, TextureParameters parameters) {
        this.resource = resource;
        this.name = name;
        this.parameters = parameters;
        this.handle = load();
    }

    private int load() {
        int[] textureHandle = new int[1];

        GLES30.glGenTextures(1, textureHandle, 0);

        BitmapFactory.Options options = new BitmapFactory.Options();
        options.inScaled = false;

        Bitmap bitmap = null;

        if (resource != -1) {
            bitmap = BitmapFactory.decodeResource(AndroidContext.context.getResources(), resource, options);
        }

        GLES30.glBindTexture(GLES30.GL_TEXTURE_2D, textureHandle[0]);

        GLES30.glTexParameteri(GLES30.GL_TEXTURE_2D, GLES30.GL_TEXTURE_WRAP_S, engineTextureWrapToGL(parameters.wrap));
        GLES30.glTexParameteri(GLES30.GL_TEXTURE_2D, GLES30.GL_TEXTURE_WRAP_T, engineTextureWrapToGL(parameters.wrap));
        GLES30.glTexParameteri(GLES30.GL_TEXTURE_2D, GLES30.GL_TEXTURE_MIN_FILTER, parameters.filter == TextureFilter.LINEAR ? GLES30.GL_LINEAR_MIPMAP_LINEAR : GLES30.GL_NEAREST);
        GLES30.glTexParameteri(GLES30.GL_TEXTURE_2D, GLES30.GL_TEXTURE_MAG_FILTER, parameters.filter == TextureFilter.LINEAR ? GLES30.GL_LINEAR : GLES30.GL_NEAREST);

        GLUtils.texImage2D(GLES30.GL_TEXTURE_2D, 0, bitmap, 0);

        GLES30.glBindTexture(GLES30.GL_TEXTURE_2D, 0);

        bitmap.recycle();

        return textureHandle[0];
    }

    public void setData(long color) {
        /* TODO */
    }

    public void bind() {
        GLES30.glBindTexture(GLES30.GL_TEXTURE_2D, handle);
    }

    public void unbind() {
        GLES30.glBindTexture(GLES30.GL_TEXTURE_2D, 0);
    }

    public int engineTextureWrapToGL(TextureWrap wrap) {
        if(wrap == TextureWrap.CLAMP_TO_EDGE)	    return GLES30.GL_CLAMP_TO_EDGE;
        if(wrap == TextureWrap.REPEAT)				return GLES30.GL_REPEAT;
        if(wrap == TextureWrap.MIRRORED_REPEAT)		return GLES30.GL_MIRRORED_REPEAT;

        return 0;
    }
}
