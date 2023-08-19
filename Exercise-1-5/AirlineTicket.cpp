module AirlineTicket;

AirlineTicket::AirlineTicket(const std::string& passengerName, const int numberOfMiles, const bool hasEliteSuperRewardStatus)
	: m_passengerName {passengerName},
	m_numberOfMiles {numberOfMiles},
	m_hasEliteSuperRewardStatus {hasEliteSuperRewardStatus}
{
}

double AirlineTicket::calcPrice() const
{
	if (hasEliteSuperRewardStatus())
		return 0;
	return numberOfMiles() * 0.1;
}