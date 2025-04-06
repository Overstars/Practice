package com.example.androidcompose.layout

import androidx.compose.foundation.Canvas
import androidx.compose.foundation.layout.size
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.geometry.CornerRadius
import androidx.compose.ui.geometry.Offset
import androidx.compose.ui.geometry.Size
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.graphics.ImageBitmap
import androidx.compose.ui.graphics.PointMode
import androidx.compose.ui.graphics.StrokeCap
import androidx.compose.ui.graphics.drawscope.Stroke
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.res.imageResource
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import com.example.androidcompose.R

@Composable
fun CanvasSample() {

    var imageBitMap : ImageBitmap? = null
    with(LocalContext.current) {
        imageBitMap = ImageBitmap.imageResource(id = R.drawable.nb)
    }

    Canvas(
        modifier = Modifier.size(200.dp)
    ) {
        drawLine(
            Color.Yellow,
            start = Offset(0f, 10f),
            end = Offset(200f, 100f),
            strokeWidth = 40f,
            cap = StrokeCap.Round
        )

        drawRect(
            color = Color.Green,
            topLeft = Offset(200f, 100f),
            size = Size(200f,200f)
        )

//        imageBitMap?.let {
//            drawImage(it, Offset(0f, 0f))
//        }

        drawRoundRect(
            color = Color.Red,
            topLeft = Offset(0f, 200f),
            size = Size(200f,200f),
            cornerRadius = CornerRadius(50f, 50f)
        )

        drawCircle(
            color = Color.Blue,
            center = Offset(200f, 200f),
            radius = 60f,
            style = Stroke(width = 40f)
        )

        drawOval(
            color = Color.Magenta,
            size = Size(100f, 300f)
        )
        drawArc(
            color = Color.Cyan,
            startAngle = 0f,
            sweepAngle = 45f,
            useCenter = true,
            style = Stroke(width = 10f)
        )

        drawPoints(
            listOf(
                Offset(100f, 100f),
                Offset(200f, 200f),
                Offset(300f, 300f),
                Offset(60f, 100f)
            ),
            pointMode = PointMode.Polygon,
            color = Color.White
        )
    }
}



@Preview
@Composable
fun CanvasSamplePreview() {
    CanvasSample()
}