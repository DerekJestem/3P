package com.example.wieczorek

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import com.example.wieczorek.ui.theme.WieczorekTheme
import android.content.Context
import android.widget.Toast
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.height
import androidx.compose.material3.Button
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.unit.dp

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            WieczorekTheme {
                Toasts()
            }
        }
    }
}

@Composable
fun Toasts() {
    val context = LocalContext.current

    Column {
        Button(onClick = { displayToast(context, "Toast 1") }) {
            Text("Toast 1")
        }
        Spacer(modifier = Modifier.height(8.dp))

        Button(onClick = { displayToast(context, "Toast 2") }) {
            Text("Toast 2")
        }
        Spacer(modifier = Modifier.height(8.dp))

        Button(onClick = { displayToast(context, "Toast 3") }) {
            Text("Toast 3")
        }
        Spacer(modifier = Modifier.height(8.dp))

        Button(onClick = { displayToast(context, "Toast 4") }) {
            Text("Toast 4")
        }
        Spacer(modifier = Modifier.height(8.dp))

        Button(onClick = { displayToast(context, "Toast 5") }) {
            Text("Toast 5")
        }

        Text("Autor: XYZ")
    }
}

fun displayToast(context: Context, msg: String) {
    val duration = Toast.LENGTH_SHORT
    val toast = Toast.makeText(context, msg, duration)
    toast.show()
}