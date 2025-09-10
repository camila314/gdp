void HardStreak::addPoint(HardStreak *this, CCPoint point) {
	m_pointArray->addObject(PointNode::create(point));
}
