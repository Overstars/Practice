package com.example.androidcompose.layout

import androidx.compose.foundation.background
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.height
import androidx.compose.material.Checkbox
import androidx.compose.material.Icon
import androidx.compose.material.Text
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.AccountBox
import androidx.compose.runtime.*
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.constraintlayout.compose.ConstraintLayout

@Composable
fun ConstrainLayoutSample() {

    var checked by remember { mutableStateOf(false) }

    ConstraintLayout(modifier = Modifier
        .fillMaxSize()
        .height(100.dp)
        .background(Color.Yellow)
    ) {
        val (icon, primaryText, secondaryText, checkbox) = createRefs(
        )

        Icon(
            Icons.Default.AccountBox,
            contentDescription = "Account",
            modifier = Modifier.constrainAs(icon) {
                top.linkTo(parent.top)
                bottom.linkTo(parent.bottom)
                start.linkTo(parent.start, 9.dp)
            }
        )
        Text(
            text = "Hello",
            fontWeight = FontWeight.Bold,
            fontSize = 16.sp,
            modifier = Modifier.constrainAs(primaryText) {
                start.linkTo(
                    icon.end,
                    margin = 9.dp,
                )
                top.linkTo(parent.top)
            }
        )

        Text(
            text = "Secondary Text",
            color = Color.Gray,
            modifier = Modifier.constrainAs(secondaryText) {
                start.linkTo(primaryText.start)
                top.linkTo(primaryText.bottom, margin = 9.dp)
                bottom.linkTo(parent.bottom)
            }
        )

        Checkbox(
            checked = checked,
            onCheckedChange = {
            checked = it
            },
            modifier = Modifier.constrainAs(checkbox) {
                centerVerticallyTo(parent)
                end.linkTo(parent.end, margin = 9.dp)
        })
    }
}

@Preview
@Composable
fun ConstrainLayoutSamplePreview() {
    ConstrainLayoutSample()
}