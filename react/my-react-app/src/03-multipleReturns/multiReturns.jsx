import { useState, useEffect } from 'react'

const MultiReturns = () => {
  const [user, setUser] = useState(null)

  const [isLoading, setIsLoading] = useState(true)
  const [isError, setIsError] = useState(false)

  const url = 'https://api.github.com/users/QuincyLarsonn'

  useEffect(() => {
    const fetchData = async () => {
      try {
        const response = await fetch(url)
        const user = await response.json()
        console.log(user)
      } catch (error) {
        console.log(error)
      }
    }
    fetchData()
  }, [])
}

export default MultiReturns
