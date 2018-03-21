package com.malepati.vikas.ftcsimulation.graphics.renderables;

import com.malepati.vikas.ftcsimulation.math.Vector2f;
import com.malepati.vikas.ftcsimulation.math.Vector3f;
import com.malepati.vikas.ftcsimulation.math.Vector4f;

import java.util.Vector;

/**
 * Created by Vikas Malepati on 3/20/2018.
 */

public abstract class Renderable2D {

    protected Vector3f position;
    protected Vector2f size;
    protected long color;

    protected Vector<Vector2f> uv;

    public Renderable2D() {
        uv.add(new Vector2f(0, 0));
        uv.add(new Vector2f(0, 1));
        uv.add(new Vector2f(1, 1));
        uv.add(new Vector2f(1, 0));
    }

    public Renderable2D(Vector3f position, Vector2f size, long color) {
        this.position = position;
        this.size = size;
        this.color = color;

        uv.add(new Vector2f(0, 0));
        uv.add(new Vector2f(0, 1));
        uv.add(new Vector2f(1, 1));
        uv.add(new Vector2f(1, 0));
    }

    public void setColor(long color) {
        this.color = color;
    }

    public void setColor(Vector4f color) {
        int r = (int) (color.x * 255.0f);
        int g = (int) (color.y * 255.0f);
        int b = (int) (color.z * 255.0f);
        int a = (int) (color.w * 255.0f);

        this.color = a << 24 | b << 16 | g << 8 | r;
    }

    public Vector3f getPosition() { return position; }
    public Vector2f getSize() { return size; }
    public long getColor() { return color; }
    public Vector<Vector2f> getUV() { return uv; }

}
