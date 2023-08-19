export module AirlineTicket;
import <string>;

export class AirlineTicket
{
private:
	std::string m_passengerName {"Unknown Passenger"};
	int m_numberOfMiles;
	bool m_hasEliteSuperRewardStatus {false};
public:
	AirlineTicket() = default;
	AirlineTicket(const std::string& passengerName, const int numberOfMiles, const bool hasEliteSuperRewardStatus);
	~AirlineTicket() = default;
public:
	std::string passengerName() const { return m_passengerName; }
	void setPassengerName(const std::string& newPassengerName) { m_passengerName = newPassengerName; }
	int numberOfMiles() const { return m_numberOfMiles; }
	void setNumberOfMiles(const int newNumberOfMiles) { m_numberOfMiles = newNumberOfMiles; }
	bool hasEliteSuperRewardStatus() const { return m_hasEliteSuperRewardStatus; }
	void setEliteSuperRewardStatus(const bool newStatus) { m_hasEliteSuperRewardStatus = newStatus; }
public:
	double calcPrice() const ;
};
