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
import androidx.compose.ui.layout.layoutId
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.constraintlayout.compose.ConstraintLayout
import androidx.constraintlayout.compose.ConstraintSet

// 创建一个ConstraintLayout示例
@Composable
fun ConstrainLayoutSample() {

    // 创建一个可变的布尔值，用于控制Checkbox的选中状态
    var checked by remember { mutableStateOf(false) }

    // 创建一个ConstraintLayout，并设置其修饰符
    ConstraintLayout(modifier = Modifier
        .fillMaxSize()
        .height(100.dp)
        .background(Color.Yellow)
    ) {
        // 创建四个引用，分别对应Icon、Text和Checkbox
        val (icon, primaryText, secondaryText, checkbox) = createRefs(
        )

        // 创建一个Icon，并设置其修饰符
        Icon(
            Icons.Default.AccountBox,
            contentDescription = "Account",
            modifier = Modifier.constrainAs(icon) {
                top.linkTo(parent.top)
                bottom.linkTo(parent.bottom)
                start.linkTo(parent.start, 9.dp)
            }
        )
        // 创建一个Text，并设置其修饰符
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

        // 创建另一个Text，并设置其修饰符
        Text(
            text = "Secondary Text",
            color = Color.Gray,
            modifier = Modifier.constrainAs(secondaryText) {
                start.linkTo(primaryText.start)
                top.linkTo(primaryText.bottom, margin = 9.dp)
                bottom.linkTo(parent.bottom)
            }
        )

        // 创建一个Checkbox，并设置其修饰符
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


// 创建另一个ConstraintLayout示例
@Composable
fun ConstrainLayoutSample2() {

    // 创建一个可变的布尔值，用于控制Checkbox的选中状态
    var checked by remember { mutableStateOf(false) }

    // 创建一个ConstraintSet，并设置其约束条件
    val constraints = ConstraintSet {
        val icon = createRefFor("icon")
        val primaryText = createRefFor("primaryText")
        val secondaryText = createRefFor("secondaryText")
        val checkbox = createRefFor("checkbox")

        // 设置Icon的约束条件
        constrain(icon) {
            centerVerticallyTo(parent)
            start.linkTo(parent.start, 9.dp)
        }
        // 设置primaryText的约束条件
        constrain(primaryText) {
            start.linkTo(icon.end, margin = 9.dp)
            top.linkTo(parent.top, margin = 8.dp)
        }
        // 设置secondaryText的约束条件
        constrain(secondaryText) {
            start.linkTo(primaryText.start)
            top.linkTo(primaryText.bottom, margin = 9.dp)
            bottom.linkTo(parent.bottom, margin = 8.dp)
        }
        // 设置checkbox的约束条件
        constrain(checkbox) {
            centerVerticallyTo(parent)
            end.linkTo(parent.end, margin = 9.dp)
        }
    }

    // 创建一个ConstraintLayout，并设置其修饰符和约束条件
    ConstraintLayout(modifier = Modifier
        .fillMaxSize()
        .height(100.dp)
        .background(Color.Yellow),
        constraintSet = constraints
    ) {

        // 创建一个Icon，并设置其修饰符
        Icon(
            Icons.Default.AccountBox,
            contentDescription = "Account",
            modifier = Modifier.layoutId("icon")
        )
        // 创建一个Text，并设置其修饰符
        Text(
            text = "Hello",
            fontWeight = FontWeight.Bold,
            fontSize = 16.sp,
            modifier = Modifier.layoutId("primaryText")
        )

        // 创建另一个Text，并设置其修饰符
        Text(
            text = "Secondary Text",
            color = Color.Gray,
            modifier = Modifier.layoutId("secondaryText")
        )

        // 创建一个Checkbox，并设置其修饰符
        Checkbox(
            checked = checked,
            onCheckedChange = {
                checked = it
            },
            modifier = Modifier.layoutId("checkbox"))
    }
}

// 创建一个预览
@Preview
@Composable
fun ConstrainLayoutSamplePreview() {
    ConstrainLayoutSample2()
}