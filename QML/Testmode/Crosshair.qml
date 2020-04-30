import QtQuick 2.0

Canvas {
    onPaint: {
        var ctx = getContext('2d')
        ctx.clearRect(0, 0, width, height)
        ctx.save()
        ctx.beginPath()
        ctx.lineWidth = 1; ctx.strokeStyle = ctx.createPattern('red', Qt.SolidLine)
        ctx.moveTo(0, 0); ctx.lineTo(width, height)
        ctx.moveTo(width, 0); ctx.lineTo(0, height)
        var diameter = Math.min(width, height)
        ctx.roundedRect(0.5 * (width - diameter), 0.5 * (height - diameter), diameter, diameter, 0.5 * diameter, 0.5 * diameter)
        diameter = diameter * 0.5
        ctx.roundedRect(0.5 * (width - diameter), 0.5 * (height - diameter), diameter, diameter, 0.5 * diameter, 0.5 * diameter)
        ctx.stroke()
        ctx.restore()
    }
    onWidthChanged: requestPaint()
    onHeightChanged: requestPaint()
}
